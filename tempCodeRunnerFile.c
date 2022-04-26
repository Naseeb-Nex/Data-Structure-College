#include<stdio.h>

struct poly{
    int ex;
    int co;
}x1[15], x2[15], x3[30];

int input(struct poly x[]){
    int c, i;
    printf("Enter the size of the Polynomial : ");
    scanf("%d", &c);
    printf("\nEnter the polinomial values : ");
    for(i=0; i<c; i++){
        printf("\nEnter the coeffe : ");
        scanf("%d", &x[i].co);
        printf("\nEnter the Exponential : ");
        scanf("%d", &x[i].ex);
    }
    return c;
}

int display(struct poly x[],int n){
    int i;
    for(i=0; i<n; i++){
        printf(" %d X ^ %d ",x[i].co,x[i].ex);
    }
    printf("\n");
}

void main(){
    printf("Enter the first polynomial :\n");
    int n = input(x1);
    printf("Enter the Second polynomial : \n");
    int m = input(x2);
    display(x1, n);
    display(x2, m);
}