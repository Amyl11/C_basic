#ifndef BST_H_
#define BST_H_

#define VERSION 2.2.2
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long value_t;

struct tnode {
  char key[256];
  value_t value;
  struct tnode *left, *right, *top;
};

struct tree {
  struct tnode *root;
  long size;
};

struct tnode *tnode(const char *key, value_t value) {
  struct tnode *nn = malloc(sizeof(struct tnode));
  strcpy(nn->key, key);
  nn->value = value;
  nn->left = nn->right = nn->top = NULL;
  return nn;
}

struct tree *tree() {
  struct tree *t = malloc(sizeof (struct tree));
  t->root = NULL;
  t->size = 0;
  return t;
}

struct tnode *tput(struct tree *t, const char *key, value_t value) {
  struct tnode *top = NULL, *n = t->root;
  int order;
  while (n) {
    order = strcmp(key, n->key);
    if (order == 0) {
      return n;
    }
    top = n;
    n = order < 0? n->left: n->right;
  }
  n = tnode(key, value);
  n->top = top;
  ++t->size;
  if (top == NULL) {
    t->root = n;
    return NULL;
  }
  if (order < 0) {
    top->left = n;
  } else {
    top->right = n;
  }
  return NULL;
}

struct tnode *left_most(struct tnode *n) {
  struct tnode *top = NULL;
  while (n) {
    top = n;
    n = n->left;
  }
  return top;
}

struct tnode *next(struct tnode *n) {
  if (n->right) {
    return left_most(n->right);
  }
  while (n->top) {
    if (n->top->left == n) {
      return n->top;
    }
    n = n->top;
  }
  return NULL;
}

struct tnode *tsearch(struct tree *t, const char *key) {
  struct tnode *n = t->root;
  while (n) {
    int o = strcmp(key, n->key);
    if (o == 0) {
      return n;
    }
    n = o < 0? n->left: n->right;
  }
  return NULL;
}

void tchange(struct tree *t, struct tnode *old, struct tnode *nn) {
  struct tnode *top = old->top;
  if (top == NULL) {
    t->root = nn;
  } else {
    if (top->left == old) {
      top->left = nn;
    } else {
      top->right = nn;
    }
  }
  if (nn) {
    nn->top = top;
  }
}

int trem(struct tree *t, const char *key) {
  struct tnode *n = tsearch(t, key);
  if (!n) {
    return 0;
  }
  struct tnode *top = n->top;
  if (n->left == NULL && n->right == NULL) {
    /* TH1:
        (n)
        / \
      NULL NULL
    */
    tchange(t, n, NULL);
    free(n);
    return 1;
  }
  struct tnode *r = n->right,
               *l = n->left;
  if (l == NULL) {
    /* TH2:
        (n)
        /  \
       NULL r
    */
    tchange(t, n, r);
    free(n);
    return 1;
  }
  if (r == NULL) {
    /* TH2:
        (n)
        / \
       l  NULL
    */
    tchange(t, n, l);
    free(n);
    return 1;
  }
  if (r->left == NULL) {
    /* TH3:
         (n)
        /   \
      (x)    r
            /  \
          NULL (y)
    */
    r->left = n->left;
    n->left->top = r;
    tchange(t, n, r);
    free(n);
    return 1;
  }
  /* TH4:
      (n)
     /  \
    (x)   r
        /   \
       nn  (y)
      /   \
     NULL (z)
  */
  struct tnode *nn = r->left, *nnt = r;
  while (nn->left) {
    nnt = nn;
    nn = nn->left;
  }
  nnt->left = nn->right;
  if (nn->right) {
    nn->right->top = nnt;
  }
  nn->left = l;
  nn->right = r;
  l->top = nn;
  r->top = nn;
  tchange(t, n, nn);
  free(n);
  return 1;
}

void rdel(struct tnode *n) {
  if (n->left) {
    rdel(n->left);
  }
  if (n->right) {
    rdel(n->right);
  }
  free(n);
}

void tdel(struct tree *t) {
  if (t->root) {
    rdel(t->root);
  }
  free(t);
}

#endif  // BST_H_