#include "dssv.h"

#include <stdio.h>
#include <stdlib.h>

struct vector *vcreate(int n){
    struct vector *v = malloc(sizeof(struct vector));
    v->sz = n;
    v->cap = n > 8 ? n:8;
    v->elems = calloc(n, sizeof(struct sinh_vien));
    return v;
}

void vreserve(struct vector *v, int new_cap){
    if(new_cap < v->cap){
        return;
    }
    v->elems = realloc(v->elems, new_cap * sizeof(struct sinh_vien));
    v->cap = new_cap;
}

void vappend(struct vector *v, struct sinh_vien value){
    if(v->cap == 0){
        vreserve(v, 16);
    }
    else if (v->cap == v->sz){
        vreserve(v, 2 * v->cap);
    }
    v->elems[v->sz] = value;
    v->sz++;
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

void vscan_elem(vec_elem_t *e){  //scanf("%d,%9[^,],%100[^,],%f", &stt, &mssv, &hoten, &hp)
    scanf("%d,", &e->stt);
    int tmp = 0;
    while(e->mssv[tmp] != ','){
        e->mssv[tmp] = getchar();
        tmp++;
    }
    tmp = 0;
    while(e->hoten[tmp] != ','){
        e->hoten[tmp] = getchar();
        tmp++;
    }
    scanf(",%f", &e->hp);
}

void vprint_elem(vec_elem_t *e){
    printf("%d,", e->stt);
    int tmp = 0;
    while(e->mssv[tmp] != '\0'){
        printf("%c", e->mssv[tmp]);
        tmp++;
    }
    printf(",");
    tmp = 0;
    while(e->hoten[tmp] != '\0'){
        printf("%c", e->hoten[tmp]);
        tmp++;
    }
    printf(",%.1f\n", e->hp);
}

int failed_count(struct vector *v){
    int count = 0;
    for(int i=0; i<v->sz; i++){
        if(v->elems+i->hp < 4){
            count++;
        }
    }
    return count;
}

vec_elem_t *first_max_hp(struct vector *v){
    int max = 0;
    for(int i=0; i<v->sz; i++){
        max = max > v->elems+i->hp ? max:v->elems+i->hp;
    }
    for(int i=0; i<v->sz; i++){
        if(v->elems+i->hp == max){
            return v->elems+i;
        }
    }
}

void solve(void){
    int n= 0;
    scanf("%d", n);
    struct vector *v = vcreate(n);
    for(int i=0; i<n; i++){
        vscan_elem(v->elems+i);
    }
    printf("&d\n", failed_count(v));
    printf("%d\n", n- failed_count(v));
    vprint_elem(first_max_hp);
}

void main(void){
    solve();
}