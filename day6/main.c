#include "slist.h"

slist_elem_t scan_node() {
    slist_elem_t elem;
    scanf("%d %d", &elem.x, &elem.y);
    return elem;
}

int main() {
    struct slist *list = slist();
    while(1) {
        slist_elem_t elem = scan_node();
        if(elem.x ==0 && elem.y ==0){
            break;
        }
        push(list, elem);
    }
    printf("%d\n", list->len);
    while(list->head) {
        struct snode *n = top(list);
        printf("%d %d\n", n->data.x, n->data.y);
        pop(list);
    }
    sdel(list);
}