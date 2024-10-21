#include "slist.h"
#include <string.h>

int dupl(struct slist *list, int k) {
    struct snode *n = list->head;
    while(1) {
        if(n->data == k) {
            return 1;
        }
        if(n->next == NULL) {
            return 0; 
        }
        n = n->next;
    }
}

struct slist *sdell(struct slist *list, int k){
    if(list->head->data == k) {
        sdelh(list);
        return list;
    }
    struct snode *n = list->head->next;
    struct snode *ctr = list->head;
    while(n != NULL) {
        if(n->data == k) {
            ctr->next = n->next;
            if(n->next == NULL) {
                list->tail = ctr;
            }
            free(n);
            list->len--;
            return list;
        }
        ctr = n;
        n = n->next;
    }
    return list;
}

struct slist *saddbefore(struct slist *list, int k, int v) {
    if(list->head->data == v) {
        sprepend(list, k);
        return list;
    }
    struct snode *nn = snode(k);
    struct snode *n = list->head->next;
    struct snode *ctr = list->head;
    while(n != NULL) {
        if(n->data == v) {
            ctr->next = nn;
            nn->next = n;
            list->len++;
            return list;
        }
        ctr = n;
        n = n->next;
    }
    return list;
}

struct slist *saddafter(struct slist *list, int k, int v) {
    struct snode *nn = snode(k);
    struct snode *n = list->head;
    struct snode *ctr = list->head->next;
    while(n != NULL) {
        if(n->data == v) {
            n->next = nn;
            nn->next = ctr;
            list->len++;
            if(ctr == NULL) {
                list->tail = nn;
            }
            return list;
        }
        n = n->next;
        ctr = n->next;
    }
    return list;
}

struct slist *sreverse(struct slist *list) {
    struct snode *n = list->head;
    struct snode *pre = NULL;
    struct snode *nxt = NULL;
    list->head = list->tail;
    list->tail = n;
    while(n != NULL) {
        nxt = n->next;
        n->next = pre;
        pre = n;
        n = nxt;
    }
    return list;
}

void srequest(struct slist *list) {
    char request[100];
    int k;
    int v;
    while(scanf("%s", request)) {
        if(!strcmp(request, "#")) {
            return;
        }
        if(!strcmp(request, "addlast")) {
            scanf("%d", &k);
            if(!dupl(list, k)) {
                sappend(list, k);
            }
        }
        if(!strcmp(request, "addfirst")) {
            scanf("%d", &k);
            if(!dupl(list, k)){
                sprepend(list, k);
            }
        }
        if(!strcmp(request, "remove")) {
            scanf("%d", &k);
            if(dupl(list, k)){
                sdell(list, k);
            }
        }
        if(!strcmp(request, "addbefore")) {
            scanf("%d %d", &k, &v);
            if(!dupl(list, k) && dupl(list, v)){
                saddbefore(list, k, v);
            }
        }
        if(!strcmp(request, "addafter")) {
            scanf("%d %d", &k, &v);
            if(!dupl(list, k) && dupl(list, v)){
                saddafter(list, k, v);
            }
        }
        if(!strcmp(request, "reverse")) {
            sreverse(list);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    struct slist *list = slist();
    for(int i=0; i<n; i++) {
        slist_elem_t tmp;
        scanf("%d", &tmp);
        sappend(list, tmp);
    }
    srequest(list);
    slist_pprint(list);
    sdel(list);
}