#include <stdio.h>

int main(){
    int a[1000] = {0};
    for(int i=1; i<=1000; i++){
        a[i-1] = i*i;
    }
    // int count[1000] = {0};
    int n;
    scanf("%d", &n);

    int index[n];
    for(int i=0; i<n; i++){
        scanf("%d", &index[i]);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<1000; j++){
            if(index[i] == a[j]){
                printf("%d\n", a[j]);
            }
        }
    }
    
}
