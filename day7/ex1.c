#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct sv {
    char date[20];
    char uid[20];
};

typedef struct sv vec_elem_t;

struct vector {
    int sz;
    int cap;
    vec_elem_t *elems;
};

#define VFOR(v,cur) for (vec_elem_t *cur = (v)->elems; cur < (v)->elems + (v)->sz; cur++)


struct vector *vcreate(int n) {
    struct vector *v = malloc(sizeof(struct vector));
    v->sz = n;
    v->cap = n > 8 ? n : 8;
    v->elems = malloc(v->cap * sizeof(vec_elem_t));
    return v;
}

void vreserve(struct vector *v, int ncap) {
    if(ncap <= v->sz) {
        return;
    }
    v->elems = realloc(v->elems, ncap * sizeof(vec_elem_t));
    v->cap = ncap;
}

void vappend(struct vector *v, vec_elem_t e) {
    if(v->cap == 0) {
        vreserve(v, 16);
    } else if(v->cap == v->sz) {
        vreserve(v, 2 * v->cap);
    }
    v->elems[v->sz] = e;
    v->sz++;
}

void vfree(struct vector *v) {
    if(!v) {
        return;
    }
    free(v->elems);
    free(v);
}

void print_vec(struct vector *v) {
    VFOR(v, cur) {
        printf("%s %s\n", cur->date, cur->uid);
    }
}

#define VSWAP(e1, e2) {\
    vec_elem_t __tmp = e1;\
    e1 = e2;\
    e2 = __tmp;\
}

void heapify(struct vector *v,int root, int (*order)(char *a, char *b)) {
    if(root > v->sz/2 -1) {
        return;
    }
    int lc = 2*root +1;
    int rc = 2*root +2;
    heapify(v,lc,order);
    if(!order(v->elems[root].date, v->elems[lc].date)) {
        VSWAP(v->elems[root], v->elems[lc]);
    }
    if(rc==v->sz) {
        return;
    }
    heapify(v,rc,order);
    if(!order(v->elems[root].date, v->elems[rc].date)) {
        VSWAP(v->elems[root], v->elems[rc]);
    }
}

int max(char *a, char *b) {
    int k = strcmp(a, b);
    if(k>0) {
        return 1;
    }
    return 0;
}

void heapsort(struct vector *v) {
    int tmp = v->sz;
    while(v->sz > 1) {
        heapify(v,0,max);
        VSWAP(v->elems[0], v->elems[v->sz-1]);
        v->sz--;
    }
    v->sz = tmp;
}

void solve(struct vector *v) {
    char tmp[20];
    int cnt = 0;
    strcpy(tmp, v->elems[0].date);
    VFOR(v, cur) {
        if(strcmp(tmp, cur->date) == 0) {
            cnt++;
        } else {
            printf("%s %d\n", tmp, cnt);
            strcpy(tmp, cur->date);
            cnt=1;
        }
    }
    printf("%s %d\n", tmp, cnt);
}

void main() {
    struct vector *v = vcreate(0);
    char input[100];
    vec_elem_t elem;
    while(scanf("%[^\n]%*c", input)) {
        if(!strcmp(input, "*")) {
            break;
        }
        sscanf(input, "%s%*s%s", elem.date, elem.uid);
        vappend(v, elem);
    }
    heapsort(v);
    solve(v);
    vfree(v);
}


