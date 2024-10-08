#ifndef VECTOR_H_
#define VECTOR_H_

typedef int vec_elem_t;

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

struct vector *vparse_marked();

void vsort(struct vector *v, int (*order)(const void *, const void *));

void solve(void);


#endif // VECTOR_H_