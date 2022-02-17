#include<stdio.h>

void insertion(int[], int);
void display(int[], int);
void sort(int[], int);

int main(){
    int n;
    printf("Enter no. of element : \n");
    scanf("%d", &n);
    int a[n];
    insertion(a,n);
    printf("Before sorting :\n");
    display(a,n);
    printf("\nAfter sorting :\n");
    sort(a,n);
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

void sort(int arr[], int l){
    int i,j,key;
    for(i=1;i<l;i++){
        key = arr[i];
        j= i-1;
        while ((j>=0)&&(arr[j]>key)){
            arr[j+1]= arr[j];
            j=j-1;
        }
        arr[j+1] = key;
    }
}

void display(int arr[], int l){
    int i;
    for(i=0; i<l;i++)
      printf("%d \t", arr[i]);
}