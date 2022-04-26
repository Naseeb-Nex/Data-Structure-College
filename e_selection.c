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

void sort(int a[], int n){
    int i,j, min;
    for(i=0;i<n;i++){
        min = i;
        for(j=i+1; j<n;j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void display(int arr[], int l){
    int i;
    for(i=0; i<l;i++)
      printf("%d \t", arr[i]);
}