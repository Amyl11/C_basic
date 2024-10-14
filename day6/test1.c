#include "slist.h"


void main(void) {
    struct slist *list = slist();
    double v=1;
    while(scanf("%lf", &v) && v > 0) {
        if(v==1) {
            sdelh(list);
        } else if (v < 10) {
            sprepend(list,v);
        } else {
            sappend(list,v);
        }
        slist_pprint(list);
    }
    sdel(list);
}