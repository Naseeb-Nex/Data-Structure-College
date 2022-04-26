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
    int i,j, key;
    for(i=1; i<n; i++){
        key = a[i];
        j = i - 1;
        while (j<0 && a[j]>=key)
        {
            a[j+1] = a[j];
            j=j--;
        }
        a[j+1] = key;
    }
}

void display(int arr[], int l){
    int i;
    for(i=0; i<l;i++)
      printf("%d \t", arr[i]);
}