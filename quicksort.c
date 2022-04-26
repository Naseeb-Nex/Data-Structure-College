#include<stdio.h>

void insertion(int[], int);
void display(int[], int);
void qsort(int[], int, int);
int partition(int[], int, int);

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


int partition(int a[], int low, int high){
    int i = low;
    int j = high;
    int x = a[low];
    while (i<=j)
    {
        while (i<high && a[i]<=x)
        {
            i++;
        }
        while (j>=0 && a[j]>x)
        {
            j--;
        }
        if(i<j){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        
        int temp = a[low];
        a[low] = a[j];
        a[j] = temp;
        return j;
    }
    
}

void qsort(int arr[], int low,int high){
    if(low<high){
        int mid = partition(arr, low, high);
        qsort(arr, low, mid -1);
        qsort(arr, mid+1, high);
    }
}


void display(int arr[], int l){
    int i;
    for(i=0; i<l;i++)
      printf("%d \t", arr[i]);
}