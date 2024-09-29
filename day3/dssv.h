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
void vappend(struct vector *v, struct sinh_vien value);
void vresize(struct vector *v, int newsize);
void vfree(struct vector *v);
void vscan_elem(vec_elem_t *e);
void vprint_elem(vec_elem_t *e);
int failed_count(struct vector *v);
vec_elem_t *first_max_hp(struct vector *v);
void solve(void);


#endif // DSSV_H_