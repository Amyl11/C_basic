#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
};

struct sll {
    struct node *head;
    struct node *tail;
    int len;
};

struct node *nnode(int n) {
    struct node *nn = malloc(sizeof(struct node));
    nn->data = n;
    nn->next = NULL;
    return nn;
}

struct sll *nsll() {
    struct sll *list = malloc(sizeof(struct sll));
    list->head = NULL;
    list->tail = NULL;
    list->len = 0;
    return list;
}

struct all *append(struct sll *list, int n) {
    struct node *nn = nnode(n);
    if(list->len == 0) {
        list->head = nn;
    } else {
        list->tail->next = nn;
    }
    list->tail = nn;
    list->len++;
    return list;
}

struct sll *preappend(struct sll *list, int n) {
    struct node *nn = nnode(n);
    if(list->len == 0) {
        list->tail = nn;
    } else {
        nn->next = list->head;
    }
    list->head = nn;
    list->len++;
    return list;
}

struct sll *zanshu(struct sll *list, int n) {
    if(list->len == 0) {
        return list;
    }
    struct node *tmp = list->head;
    list->head = list->head->next;
    free(tmp);
    list->len--;
    return list;
}

struct push(struct sll *list, int n) {
    preappend(list, n);
    return list;
}

struct pop(struct sll *list, int n) {
    zanshu(list, n);
    return list;
}

struct enq(struct sll *list, int n) {
    append(list, n);
    return list;
}

struct deq(struct sll *list, int n) {
    zanshu(list, n);
    return list;
}

int main() {

}