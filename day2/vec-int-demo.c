#include "vec.h"
#include <stdio.h>

int main() {
  int n;
  struct vector *v = vcreate(0);
  scanf("%d", &n);
  int tmp;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &tmp);
    vappend(v, tmp);
  }
  vprint(v);
  vrprint(v);
  voutput(v, 3);
  vinput(v, 4);
  vprint(v);
  vfree(v);
}