#include <stdio.h>
#include <stdlib.h>

typedef int slist_elem_t;

struct snode {
    slist_elem_t data;
    struct snode *next;
};

struct slist {
    struct snode *head, *tail;
    int len;
};


struct snode *snode(slist_elem_t elem) {
    struct snode *nn = malloc(sizeof(struct snode));
    nn->data = elem;
    nn->next = NULL;
    return nn;
}


struct slist *slist() {
    struct slist *list = malloc(sizeof(struct slist));
    list->len = 0;
    list->head = list->tail = NULL;
    return list;
}

struct slist *sappend(struct slist *list, slist_elem_t elem) {
    struct snode *nn = snode(elem);
    if (list->tail == NULL) {
        list->head = list->tail = nn;
        list->len = 1;
        return list;
    }
    list->tail->next = nn;
    list->tail = nn;
    list->len++;
    return list;
}

struct slist *sprepend(struct slist *list, slist_elem_t elem) {
    struct snode *nn = snode(elem);
    if(list->head == NULL) {
        list->head = list->tail = nn;
        list->len = 1;
        return list;
    }
    nn->next = list->head;
    list->head = nn;
    list->len++;
    return list;
}

struct slist *sdelh(struct slist *list) {
    struct snode *tmp = list->head->next;
    free(list->head);
    list->head = tmp;
    list->len--;
    if (list->len == 0) {
        list->tail = NULL;
    }
    return list;
}

int smt(struct slist *list) {
    if(list->head == NULL) {
        return 0;
    }
    return 1;
}

void slist_pprint(struct slist *list) {
    printf("len: %d\n", list->len);
    struct snode *n = list->head;
    while(n) {
        printf(" %d", n->data);
        n = n->next;
    }
    printf("\n");
}

void sdel(struct slist *list) {
    struct snode *n = list->head;
    while(n) {
        struct snode *tmp = n->next;
        free(n);
        n = tmp;
    }
}

struct snode *top(struct slist *list) {
    return list->head;
}

struct slist *pop(struct slist *list) {
    return sdelh(list);
}

struct slist *push(struct slist *list, slist_elem_t elem) {
    return sprepend(list, elem);
}

struct snode *peek(struct slist *list) {
    return list->head;
}

struct slist *enq(struct slist *list, slist_elem_t elem) {
    return sappend(list, elem);
}

struct slist *deq(struct slist *list) {
    return sdelh(list);
}