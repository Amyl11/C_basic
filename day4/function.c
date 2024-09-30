#include "dssv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct vector *vcreate(int n){
    struct vector *v = malloc(sizeof(struct vector));
    v->sz = n;
    v->cap = n>8 ? n:8;
    v->elems = calloc(n, sizeof(vec_elem_t));

    return v;
}

void vreserve(struct vector *v, int new_cap){
    if(new_cap < v->cap) {
        printf("Something went wrong\n");
        return;
    }
    v->elems = realloc(v->elems, new_cap * sizeof(vec_elem_t));
    v->cap = new_cap;
}

void vappend(struct vector *v, vec_elem_t value) {
    if(v->cap == 0) {
        vreserve(v, 16);
    }
    else if(v->sz == v->cap) {
        vreserve(v, 2 * v->cap);
    }
    v->elems[v->sz] = value;
    v->sz++;
}

void resize(struct vector *v, int newsize) {
    if(newsize > v->cap) {
        vreserve(v, newsize);
    }
    v->sz = newsize;
}

void vfree(struct vector *v) {
    if(!v) {
        return;
    }
    free(v->elems);
    free(v);
}

void vscan_elem(vec_elem_t *e) {
    scanf("%d,%[^,],%[^,],%f", &e->stt, e->mssv, e->hoten, &e->hp);
}

void vprint_elem(vec_elem_t *e) {
    printf("%d,%s,%s,%f", e->stt, e->mssv, e->hoten, e->hp);
}

struct vector *vparse_marked(){
    struct vector *v = vcreate(0);
    while (1) {
        vec_elem_t i;
        int z = vscan_elem(&i);
        if(z < 4) {
            break;
        }
        vappend(v, i);
    }
    return v;
}


void vsort(struct vector *v) {
    for(vec_elem_t *i = v->elems; i < v->elems + v->sz; i++) {
        for(vec_elem_t *j = v->elems; j < (vec_elem_t *)(v->elems + v->sz - i - 1); j++) {
            if((j->hp < (j+1)->hp) || (j->hp == (j+1)->hp && j->mssv == (j+1)->mssv)) {
                vec_elem_t tmp = v->elems[i];
                v->elems[i] = v->elems[j];
                v->elems[j] = tmp;
            }
        }
    }
}

vec_elem_t *vsearch(struct vector *v, char key[]) {
    for(vec_elem_t *i = v->elems; i<v->elems+v->sz; i++) {
        if(!strcmp(i->mssv, key)) {
            return i;
        }
    }
}


void solve(void) {
    char end[] = "*****";
    struct vector *v = vparse_marked();
    // printf("%d", n);
    vsort(v);
    for(vec_elem_t *i = v->elems; i<v->elems+v->sz; i++) {
        vprint_elem(i);
    }


    // while (1) {
    //     char key[10];
    //     scanf("%s", &key);
    //     if(!strcmp(key, end)) {
    //         break;
    //     }
    //     vprint_elem(vsearch(v, key));
    // }


}