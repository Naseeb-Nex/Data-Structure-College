#include<stdio.h>

int front = -1,rear = -1;
int q[50];
void enqueue(int data,int l)//Enqueue for inserting data
{
    if(rear==l-1){
        printf("Queue is full");
    }
    else if((front==-1)&&(rear==-1)){
        front = rear = 0;
        q[rear] = data;
    }
    else
    {
        rear++;
        q[rear] = data;    
    }
}
void print()
{
    int i;
    for(i=front;i<=rear;i++)
    {
        printf("\n%d",q[i]);
    }
}
void reverse()
{
    int i,j,t;
    for(i=front,j=rear;i<j;i++,j--){
        t = q[i];
        q[i] = q[j];
        q[j] = t;
    }
}
void main()
{
    int n,i=0,t;
    printf("Enter the size of the Queue : ");
    scanf("%d",&n);
    printf("\nEnter the data for the Queue : \n");
    while(i<n){
        scanf("%d",&t);
        enqueue(t,n);
        i++;
    }
    printf("\nQueue which you have entered :- \n");
    print();
    reverse();
    printf("\nQueue after reversing :- \n");
    print();
    
}