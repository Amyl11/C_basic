#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    double *a = malloc(n * sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%lf", &a[i]);
    }
    for(int i=n-1; i>= 0; i--){
        printf("%.2lf ", a[i]);
    }
    free(a);
    }