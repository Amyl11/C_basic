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

struct sll *append(struct sll *list, int n) {
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

int exist(struct sll *list, int n) {
    struct node *tmp = list->head;
    for(int i=0; i<list->len; i++) {
        if(tmp->data == n) {
            return 1; //mean exist;
        }
        tmp = tmp->next;
    }
    return 0; //mean not exist;
}

struct sll *addafter(struct sll *list, int u, int v) {
    if(list->tail->data == v) {
        append(list,u);
        return list;
    }
    if(exist(list, v) && !exist(list, u)) {
        struct node *nu = nnode(u);
        struct node *tmp = list->head;
        for(int i=0; i<list->len; i++) {
            if(tmp->data == v) {
                nu->next = tmp->next;
                tmp->next = nu;
                list->len++;
                return list;
            }
            tmp = tmp->next;
        }
    }
    return list;
}

struct sll *addbefore(struct sll *list, int u, int v) {
    if(list->head->data == v) {
        preappend(list,u);
        return list;
    }
    if(exist(list, v) && !exist(list, u)) {
        struct node *nu = nnode(u);
        struct node *tmp = list->head;
        struct node *pre = NULL;
        for(int i=0; i<list->len; i++) {
            if(tmp->data == v) {
                pre->next = nu;
                nu->next = tmp;
                list->len++;
                return list;
            }
            pre = tmp;
            tmp = tmp->next;
        }
    }
    return list;
}

struct sll *nremove(struct sll *list, int n) {
    if(list->head->data == n) {
        struct node *tmp = list->head;
        list->head = tmp->next;
        free(tmp);
        list->len--;
        return list;
    }
    struct node *tmp = list->head;
    struct node *pre = NULL;
    for(int i=0; i<list->len; i++) {
        if(tmp->data == n) {
            if(tmp == list->tail) {
                list->tail = pre;
            }
            pre->next = tmp->next;
            free(tmp);
            list->len--;
            return list;
        }
        pre = tmp;
        tmp = tmp->next;
    }
    return list;
}

struct sll *reverse(struct sll *list) {
    if(list->len <= 1) {
        return list;
    }
    struct node *tmp = list->head;
    struct node *pre = NULL;
    struct node *nxt = NULL;
    list->head = list->tail;
    list->tail = tmp;
    for(int i=0; i<list->len; i++) {
        nxt = tmp->next;
        tmp->next = pre;
        pre = tmp;
        tmp = nxt;
    }
    return list;
}

void sllprint(struct sll *list) {
    struct node *n = list->head;
    printf("len: %d\n", list->len);
    for(int i=0; i<list->len; i++) {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

struct sll *addlast(struct sll *list, int n) {
    if(!exist(list,n)) {
        append(list,n);
    }
    return list;
}

struct sll *addfirst(struct sll *list, int n) {
    if(!exist(list,n)) {
        preappend(list,n);
    }
    return list;
}

int main() {
    struct sll *list = nsll();
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int tmp;
        scanf("%d", &tmp);
        append(list, tmp);
    }
    char input[20];
    while(scanf("%s", input)) {
        if(!strcmp(input, "#")) {
            break;
        }
        if(!strcmp(input, "addlast")) {
            int u;
            scanf("%d", &u);
            addlast(list,u);
        }
        if(!strcmp(input, "addfirst")) {
            int u;
            scanf("%d", &u);
            addfirst(list,u);
        }
        if(!strcmp(input, "addafter")) {
            int u;
            int v;
            scanf("%d %d", &u, &v);
            addafter(list,u,v);
        }
        if(!strcmp(input, "addbefore")) {
            int u;
            int v;
            scanf("%d %d", &u, &v);
            addbefore(list,u,v);
        }
        if(!strcmp(input, "remove")) {
            int u;
            scanf("%d", &u);
            nremove(list,u);
        }if(!strcmp(input, "reverse")) {
            reverse(list);
        }
    }
    sllprint(list);
}