#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct date {
  int y;
  int m;
  int d;
};

struct vec_elem_t {
  struct date day;
  int h;
  int m;
  int s;
  char uid[15];
  char qid[15];
};

typedef struct vec_elem_t vec_elem_t;

struct vector {
  int sz;
  int cap;
  vec_elem_t *elems;
};

#define VFOR(v, cur) for (vec_elem_t *cur = (v)->elems; cur < (v)->elems + (v)->sz; cur++)

struct vector *vcreate(int n) {
  struct vector *v = malloc(sizeof(struct vector));
  v->sz = n;
  v->cap = v->sz > 0? v->sz: 8;
  v->elems = calloc(v->cap, sizeof(vec_elem_t));
  return v;
}

void vreserve(struct vector *v, int newcap) {
  if (newcap <= v->sz) {
    return;
  }
  v->elems = realloc(v->elems, newcap * sizeof(vec_elem_t));
  if (v->cap < newcap) {
    memset(v->elems + v->cap, 0, sizeof(vec_elem_t) * (newcap - v->cap));
  }
  v->cap = newcap;
}

void vappend(struct vector *v, vec_elem_t value) {
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

void vfree(struct vector *v) {
  if (!v) {
    return;
  }
  free(v->elems);
  free(v);
}

struct vector *vscan() {
  struct vector *v = vcreate(0);
  char input[100];
  while(1) {
    scanf("%s\n", input);
    if(strcmp(input, "*")){
      return v;
    }
    sscanf("%d-%d-%d %d:%d:%d %[^ ] %[^\n]", input, &v->elems->day.y, &v->elems->day.m, &v->elems->day.d, &v->elems->h, &v->elems->m, &v->elems->s, v->elems->uid, v->elems->qid);
  }
}

void vprint(struct vector *v) {
  VFOR(v, cur) {
    printf("%d-%d-%d %d:%d:%d %s %s\n", v->elems->day.y, v->elems->day.m, v->elems->day.d, v->elems->h, v->elems->m, v->elems->s, v->elems->uid, v->elems->qid);
  }
  return;
}


int main() {
  struct vector *v = vscan(0);
  vprint(v);
  vfree(v);
}