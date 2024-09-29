#include "vec.h"

#include <stdio.h>
#include <stdlib.h>

struct vector *vcreate(int n) {
  struct vector *v = malloc(sizeof(struct vector));
  v->sz = n;
  v->cap = v->sz > 0? v->sz: 8;
  v->elems = calloc(v->cap, sizeof(int));
  return v;
}

void vreserve(struct vector *v, int newcap) {
  if (newcap <= v->sz) {
    return;
  }
  v->elems = realloc(v->elems, newcap * sizeof(int));
  v->cap = newcap;
}

void vappend(struct vector *v, int value) {
  if (v->cap == 0) {
    vreserve(v, 16);
  } else if (v->sz == v->cap) {
    vreserve(v, 2 * v->cap);
  }
  v->elems[v->sz] = value;
  ++v->sz;
}

void vresize(struct vector *v, int newsize) {
  if (newsize > v->cap) {
    vreserve(v, newsize);
  }
  v->sz = newsize;
}

void vprint(struct vector *v) {
  printf("size: %d cap: %d\n", v->sz, v->cap);
  for (int i = 0; i < v->sz; ++i) {
    printf(" %d", v->elems[i]);
  }
  printf("\n");
}

void vrprint(struct vector *v) {
  printf("size: %d cap: %d\n", v->sz, v->cap);
  for (int i = v->sz - 1; i >= 0; --i) {
    printf(" %d", v->elems[i]);
  }
  printf("\n");
}

void vinput(struct vector *v, int idx) {
  printf("nhap gia tri cho phan tu thu %d:\n", idx);
  scanf("%d", &(v->elems[idx-1]));
}

void voutput(struct vector *v, int idx) {
  printf("phan tu thu %d la: %d\n", idx, v->elems[idx-1]);
}

void vfree(struct vector *v) {
  if (!v) {
    return;
  }
  free(v->elems);
  free(v);
}