#include<stdio.h>

void insertion(int arr[], int l){
    int i;
    printf("Enter the element : \n");
    for(i=0;i<l;i++){
        scanf("%d", &arr[i]);
    }
}

void display(int arr[], int l){
    int i;
    for(i=0; i<l;i++)
      printf("%d \t", arr[i]);
}


void merge(int a[], int low, int mid, int high){
    int b[50];
    int i = low, k = low, j = mid+1;
    while(i<=mid && j<=high){
        if(a[i]<=a[j]){
            b[k] = a[i];
            i++;
            k++;
        }else{
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i<=mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j<=high)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    

    for(i=low; i<=high; i++){
        a[i]= b[i];
    }
    
}

void mergesort(int a[], int low, int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        mergesort(a, low, mid);
        mergesort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}


int main(){
    int n;
    printf("Enter no. of element : \n");
    scanf("%d", &n);
    int a[n];
    insertion(a,n);
    printf("Before sorting :\n");
    display(a,n);
    printf("\nAfter sorting :\n");
    mergesort(a, 0, n-1);
    display(a,n);
    return 0;
}

