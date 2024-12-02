#include "bst.h"

// struct tnode *tadd(struct tree *t, char *key, value_t value) {
//     struct tnode *nn = tnode(key, value);
//     if(t->root == NULL) {
//         t->root = nn;
//     }
//     struct tnode *top = t->root;
//     while(top->right) {
//         top = top->right;
//     }
//     top->right = nn;
//     return nn;
// }

void main() {
    long n;
    scanf("%ld", &n);
    struct tree *MatHang = tree();
    for(long i=0; i<n; i++) {
        char key[10];
        long value = 0;
        scanf("%s %ld", key, &value);
        tput(MatHang, key, value);
    }

    struct tree *cart = tree();
    long m;
    scanf("%ld", &m);
    int k;
    for(long i=0; i<m; i++) {
        long sum=0;
        scanf("%d", &k);
        for(int j=0; j<k; j++) {
            char key[10];
            int count = 0;
            scanf("%s %d", key, &count);

            // tadd(cart, key, count);
            struct tnode *current = tsearch(MatHang, key);
            sum += current->value * count;
        }
        printf("%ld\n", sum);
    }
    tdel(MatHang);
    // struct tnode *cur = cart->root;

}