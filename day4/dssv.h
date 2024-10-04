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

#define VFOR(v, cur) for (vec_elem_t *cur = (v)->elems; cur < (v)->elems + (v)->sz; cur++)

struct vector *vcreate(int n);
void vreserve(struct vector *v, int new_cap);
void vappend(struct vector *v, vec_elem_t value);
void vresize(struct vector *v, int new_size);
void vfree(struct vector *v);

void vprint_elem(vec_elem_t *e);

struct vector *vparse_marked();

void vsort(struct vector *v, int (*order)(const void *, const void *));
int hpdecrease(const void *a, const void *b);


void vsearch(struct vector *v, char key[]);
int readfor_search(char **data);


void solve(void);


#endif // DSSV_H_