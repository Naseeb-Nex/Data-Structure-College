#include<stdio.h>

void insertion(int[], int);
void display(int[], int);
void qsort(int[], int, int);

int main(){
    int n;
    printf("Enter no. of element : \n");
    scanf("%d", &n);
    int a[n];
    insertion(a,n);
    printf("Before sorting :\n");
    display(a,n);
    printf("\nAfter sorting :\n");
    qsort(a,0,n);
    display(a,n);
    return 0;
}

void insertion(int arr[], int l){
    int i;
    printf("Enter the element : \n");
    for(i=0;i<l;i++){
        scanf("%d", &arr[i]);
    }
}

void qsort(int arr[], int low,int high){
    if(low<high){
        int mid = partition(arr, low, high)
    }

     
}

void display(int arr[], int l){
    int i;
    for(i=0; i<l;i++)
      printf("%d \t", arr[i]);
}