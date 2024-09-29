#include <stdio.h>
#include <stdlib.h>

void print(int *a, int n){
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){
    const int n = 10;
    // int *a = malloc(1000 * sizeof(int));
    // for(int i = 0; i < n; i++){
    //     a[i] = i+1;
    // }
    // free(a);
    int *a = malloc(n * sizeof(int));
    int *b = calloc(n, sizeof(int));
    print(a, n);
    print(b, n);
}