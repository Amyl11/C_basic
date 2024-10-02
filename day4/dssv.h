#ifndef DSSV_H_
#define DSSV_H_

struct sinh_vien{
    int stt;
    char mssv[10];
    char hoten[101];
    float hp;
};
typedef struct sinh_vien vec_elem_t;

struct vector {
    int sz;
    int cap;
    vec_elem_t *elems;
};

struct vector *vcreate(int n);
void vreserve(struct vector *v, int new_cap);
void vappend(struct vector *v, vec_elem_t value);
void vresize(struct vector *v, int newsize);
void vfree(struct vector *v);

void vscan_elem(vec_elem_t *e);
void vprint_elem(vec_elem_t *e);

void vparse_marked();

void vswap(vec_elem_t *e, vec_elem_t *t);
void vsort(struct vector *v);
vec_elem_t *vsearch(struct vector *v, char key[]);

void solve(void);


#endif // DSSV_H_