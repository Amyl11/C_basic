#include "dssv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct vector *vcreate(int n) {
    struct vector *v = malloc(sizeof(struct vector));
    v->sz = n;
    v->cap = v->sz > 8 ? v->sz : 8;
    v->elems = calloc(v->cap, sizeof(vec_elem_t));
    return v;
}

void vreserve(struct vector *v, int new_cap) {
    if(new_cap <= v->sz) {
        return;
    }
    v->elems = realloc(v->elems, new_cap * sizeof(vec_elem_t));
    if(v->cap < new_cap) {
        memset(v->elems + v->cap, 0, sizeof(vec_elem_t) * (new_cap - v->cap));
    }
    v->cap = new_cap;
}

void vappend(struct vector *v, vec_elem_t value) {
    if(v->cap == 0) {
        vreserve(v, 16);
    } else if(v->cap == v->sz) {
        vreserve(v, 2 * v->cap);
    }
    v->elems[v->sz] = value;
    v->sz++;
}

void vresize(struct vector *v, int new_size) {
    if(new_size > v->cap) {
        vreserve(v, new_size);
    }
    v->sz = new_size;
}

void vfree(struct vector *v) {
    if(!v) {
        return;
    }
    free(v->elems);
    free(v);
}

void vprint_elem(vec_elem_t *e) {
    printf("%d,%s,%s,%.1f\n", e->stt, e->mssv, e->hoten, e->hp);
}

struct vector *vparse_marked() {
    struct vector *v = vcreate(0);
    char input[150] = {0};
    vec_elem_t e;
    while(1) {
        scanf("%[^\n]%*c", input);
        if(strcmp(input, "*****") == 0) {
            break;
        }
        sscanf(input, "%d,%[^,],%[^,],%f", &e.stt, e.mssv, e.hoten, &e.hp);
        vappend(v, e);
    }
    return v;
}

void vsort(struct vector *v, int (*order)(const void *, const void *)) {
    for(int i = 0; i < v->sz - 1; i++) {
        for(int j = i + 1; j < v->sz; j++) {
            if(!order(v->elems + i, v->elems + j)) {
                vec_elem_t tmp = v->elems[i];
                v->elems[i] = v->elems[j];
                v->elems[j] = tmp;
            }
        }
    }
}

int hpdecrease(const void *a, const void *b) {
    const vec_elem_t *e1 = a, *e2 = b;
    if(e1->hp < e2->hp) {
        return 0;
    } else if(e1->hp > e2->hp) {
        return 1;
    }
    if(strcmp(e1->mssv, e2->mssv) < 0) {
        return 1;
    }
    return 0;
}

void vsearch(struct vector *v, char key[]) {
    VFOR(v, cur) {
        if(strcmp(cur->mssv, key) == 0) {
            vprint_elem(cur);
            return;
        }
    }
}

int readfor_search(char **data) {
    int count = 0;
    while(1) {
        char tmp[150];
        scanf("%[^\n]%*c", tmp);
        if(strcmp(tmp, "*****") == 0) {
            break;
        }
        strcpy(data[count], tmp);
        count++;
    }
    return count;
}

void solve() {
    struct vector *v = vparse_marked();
    vsort(v, hpdecrease);
    printf("%d\n", v->sz);
    VFOR(v, cur) {
        vprint_elem(cur);
    }

    char **data = (char **)malloc(v->sz * sizeof(char *));
    for(int i = 0; i < v->sz; i++) {
        data[i] = (char *)malloc(150 * sizeof(char));
    }

    int count = readfor_search(data);

    // int count = 0;
    // while(1) {
    //     char tmp[150];
    //     scanf("%[^\n]%*c", tmp);
    //     if(strcmp(tmp, "*****") == 0) {
    //         break;
    //     }
    //     data[count] = (char *)malloc((strlen(tmp)+1) * sizeof(char));
    //     strcpy(data[count], tmp);
    //     count++;
    // }
    printf("%d\n", count);
    for(int i=0; i<=count; i++) {
        vsearch(v, data[i]);
    }
    for(int i=0; i<v->sz; i++) {
        free(data[i]);
    }
    free(data);
    vfree(v);
}
