#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

#define VSWAP(e1, e2) { \
    vec_elem_t _tmp = e1; \
    e1 = e2; \
    e2 = _tmp; \
}

void heapify(struct vector *v,int root, int (*order)(void *a, void *b)) {
    if(root > v->sz/2-1) {
        return;
    }
    int orderist = root;
    int lc = 2 * root + 1;
    int rc = 2 * root + 2;
    heapify(v,lc,order);
    if(!order(v->elems + root, v->elems + lc)) {
        VSWAP(v->elems[root], v->elems[lc]);
    }
    heapify(v,rc,order);
    if(!order(v->elems + root, v->elems + rc)) {
        VSWAP(v->elems[root], v->elems[rc]);
    }
    // if (lc < v->sz && order(v->elems + lc, v->elems + orderist))
    //     orderist = lc;

    // if (rc < v->sz && order(v->elems + rc, v->elems + orderist))
    //     orderist = rc;

    // if (orderist != root) {
    //     VSWAP(v->elems[root], v->elems[orderist]);
    //     heapify(v, orderist, order);
    // }
}

int less(void *a, void *b) {
    vec_elem_t *e1 = a;
    vec_elem_t *e2 = b;
    if(*e1 <= *e2) {
        return 1;
    }
    return 0;
}

int larger(void *a, void *b) {
    vec_elem_t *e1 = a;
    vec_elem_t *e2 = b;
    if(*e1 >= *e2) {
        return 1;
    }
    return 0;
}

void main(void) {
    int he[] = {4, 9, 5, 3, 7, 1, 8, 2, 6, 0, 10};
    struct vector *v = vcreate(0);
    int n = sizeof(he)/sizeof(he[0]);
    for(int i = 0; i < n; i++) {
        vappend(v, he[i]);
    }

    VFOR(v, cur) {
        printf("%d ", *cur);
    }
    printf("\n");


    printf("%d\n", v->sz);

    heapify(v,0,larger);
    VFOR(v, cur) {
        printf("%d ", *cur);
    }
    printf("\n");
}