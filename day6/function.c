#include "slist.h"

struct slist *sparse_marked(){
    struct slist *list = slist();
    slist_elem_t elem = -2;
    while(1) {
        scanf("%d", &elem);
        if(elem == -1) {
            break;
        }
        sappend(list,elem);
    }
    return list;
}

int main() {
    struct slist *list = sparse_marked();
    slist_pprint(list);
}