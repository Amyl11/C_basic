#include <stdio.h>

// int main(){
//     int a=6;
//     int b=5;
//     int c=(a+b)/2;
//     printf("%d",c);
// }

int swap(int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

int sort(int p, int q, int a[]){
    int pivot = a[q];
    int marker = p-1;
    for(int j=p; j<=q; j++){
        if(a[j] <= pivot){
            marker++;
            if(j>marker){
                swap(&a[j], &a[marker]);
            }
        }
    }
    return marker;
}

int quick_sort(int p, int q, int a[]){
    if(p<q){
        int med = sort(p,q,a);
    quick_sort(p, med-1,a);
    quick_sort(med+1,q,a);
    }
}

int distant(int n, int a[]){
    for(int i=n; i>0; i--){
        if(a[i] - a[i-1] > 0){
            a[i] = 1;
        }
        else if(a[i] - a[i-1] < 0){
            a[i] = -1;
        }
        else{
            a[i] = 0;
        }
    }
    a[0] = 0;
}




int compare_array(int n, int a[], int b[]){
    for(int i=0; i<n; ++i){
        if(a[i] != b[i]){
            return 0;
        }
    }
    return 1;
}

int compare_group(int n, int a[], int b[]){
    quick_sort(0,n-1,a);
    quick_sort(0,n-1,b);
    return compare_array(n,a,b);
}


int compare_graph(int n, int a[], int b[]){
    distant(n,a);
    distant(n,b);
    return compare_array(n,a,b);
}

int main(){
    int n;
    printf("nhap n: \n");
    scanf("%d", &n);
    int a[n];
    int b[n];
    printf("mang 1:\n");
    for(int i=0; i<n; ++i){
        scanf("%d", &a[i]);
    }

    printf("mang 2:\n");
    for(int i=0; i<n; ++i){
        scanf("%d", &b[i]);
    }


    printf("%d", compare_graph(n,a,b));

}
