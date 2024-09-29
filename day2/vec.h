#ifndef VEC_H_
#define VEC_H_

struct vector {
  int sz;
  int cap;
  int *elems;
};

struct vector *vcreate(int n);
void vreserve(struct vector *v, int new_cap);
void vappend(struct vector *v, int elem);  // x 2
void vresize(struct vector *v, int new_sz);
void vprint(struct vector *v);
void vrprint(struct vector *v);
void vinput(struct vector *v, int idx); // scanf giá trị cho phần tử thứ i
void voutput(struct vector *v, int idx); // printf giá trị cho phần tử thứ i
void vfree(struct vector *v);

#endif  // VEC_H_