#include <stdio.h>

#define max 999999999
/*
    nhập vào một số để cài đặt độ dài cho mảng
    nhập vào các số thực của mảng
    reverse: trả về mảng đảo ngược
    average: trả về các phần tử có giá trị gần giá trị trung bình nhất
*/

double reverse(int n,double a[]){
    for(int i=n-1; i >=0; i--)
    {
        printf("%0.4f ", a[i]);
    }
    printf("\n");
}

double average(int n, double a[]){
    double sum=0;
    for(int i=0; i<n; ++i){
        sum += a[i];
    }

    double avg = sum/n;
    double mindiff = max;

    for(int i=0; i<n; ++i){
        if ((a[i] - avg) > 0){
            if (a[i] - avg < mindiff){
                mindiff = a[i] - avg;
            }
        }
        else{
            if (avg - a[i] < mindiff){
                mindiff = avg - a[i];
            }
        }
    }

    for(int i=0; i<n; ++i){
        if(a[i] - avg ==mindiff){
            printf("%.4lf ", a[i]);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    double a[n];
    for(int i=0; i<n; i++)
    {
        scanf("%lf", &a[i]);
    }
    //reverse(n,a);
    average(n, a);
}