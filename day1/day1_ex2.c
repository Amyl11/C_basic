#include <stdio.h>

/*
    nhập vào một xâu các kí tự thường
    in ra tần số xuất hiện của các chữ cái trong xâu
*/

int main(){
    int count[26] = {0};
    char c = '\0';
    c = getchar();
    while(c != '\0' && c != '\n'){
        if(c >= 'a' && c <= 'z'){
            count[c - 'a']++;
        }
        else if(c >= 'A' && c <= 'Z'){
            count[c - 'A']++;
        }
        c = getchar();
    }
    for(int i=0; i<26; ++i){
        if(count[i]!=0){
            printf("%c: %d\n", 'a'+i,count[i]);
        }
    }    
}