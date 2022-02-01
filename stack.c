#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
} *head;

void push();
void pop();
void display();

int main(){
int ch;
char c;
while (1)
{
    printf("**************************\n********Stack using Linked List*******\n**********Menu************\n1.PUSH\n2.POP\n3.DISPLAY\n**************************\nEnter your choice : ");
    scanf("%d",&ch);
    switch (ch)
    {
        case 1 : push();
                 break;
        case 2 : pop();
                 break;
        case 3 : display();
                 break; 
        default: printf("Enter a valid choice !!");
                 break;
    }
	printf("\nDo you want to continue y/n ?");
	scanf(" %c",&c);
	if(c == 'n'){
		break;
	}
}
return 0;
}
void push(){
    int data;
    struct node *temp;
    temp = malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Memory Underflowed!! no insertion");
    }
    else{
        printf("Enter the Number : ");
        scanf("%d",&data);
        temp->data=data;
        temp->next=head;
        head=temp;
    }

}
void pop(){
    if(head==NULL){
        printf("Underflow !!");
    }
    else{
        printf("%d Poped from the stack",head->data);
        head=head->next;
    }
}
void display(){
    struct node *temp;
    temp=head;
    if (temp==NULL)
    {
        printf("Empty Stack!!");
    }
    else{
        while (temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp = temp->next;
        }
        
    }
    
}