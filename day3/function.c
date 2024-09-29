#include "dssv.h"
#include <stdio.h>
#include <stdlib.h>

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
    scanf("%d,%9[^,],%100[^,],%f", &e->stt, &e->mssv, &e->hoten, &e->hp);
}

void vprint_elem(vec_elem_t *e) {
    printf("%d,%s,%s,%f", e->stt, e->mssv, e->hoten, e->hp);
}

int failed_count(struct vector *v) {
    int count = 0;
    for(vec_elem_t *i=v->elems; i<v->elems+v->sz; i++) {
        if(i->hp < 4) {
            count++;
        }
    }
    return count;
}

vec_elem_t *first_max_hp(struct vector *v) {
    int tophp = 0;
    vec_elem_t *p = NULL;
    for(vec_elem_t *i=v->elems; i<v->elems+v->sz; i++) {
        if(tophp < i->hp) {
            tophp = i->hp;
            p = i;
        }
    }
    return p;
}

void solve(void) {
    int n = 0;
    scanf("%d", &n);
    struct vector *v = vcreate(n);
    for(vec_elem_t *i=v->elems; i<v->elems+v->sz; i++) {
        vscan_elem(i);
    }
    printf("%d\n", failed_count(v));
    printf("%d\n", n - failed_count(v));
    vprint_elem(first_max_hp(v));
}