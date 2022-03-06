#include<stdio.h>
#include<string.h>

int main(){
    char s[20];
    int i, l, flag=0;
    printf("Enter a word : ");
    scanf(" %s", &s);
    l = strlen(s);
    for ( i=0; i<l; i++){
        if (s[i] != s[l-i-1]){
            flag =1;
        }
    }
    if(flag == 0){
        printf("Palindrome");
    }
    else{
        printf("not Palindrome");
    }
}