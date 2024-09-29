#include <stdio.h>


int main(){
    int n = 0;
    scanf("%d", &n);

    int a[n];

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    int sum = a[0];

    for(int i=1; i<n; i++){
        sum += a[i];
    }
    printf("tong la: %d", sum);
}