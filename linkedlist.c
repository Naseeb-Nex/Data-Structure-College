#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;

void insertatbeg();
void insertatend();
void insertatspec();
void display();
void deleteatbeg();
void deleteatend();
void deleteatspec();


int main(){
    char c;
    int ch;

    while (1)
    {
        printf("**************************\n********Linked List*******\n**********Menu************\n  1, Insert at Beginning\n  2, Insert at End \n  3, Insert at a specified Position\n  4, Diplay\n  5, Delete at Beginning\n  6, Delete at End \n  7, Delete at a specified Position\n**************************\n  Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertatbeg();
            break;
        
        case 2:
            insertatend();
            break;
        
        case 3:
            insertatspec();
            break;
        
        case 4:
            display();
            break;
        
        case 5:
            deleteatbeg();
            break;
        
        case 6:
            deleteatend();
            break;
        
        case 7:
            deleteatspec();
            break;

        default:
            printf("Enter a valid choice !!");
            break;
        }
        printf("\n  Do you want to continue y/n ?\n");
		scanf(" %c",&c);
		if(c == 'n')
			break;

    }
    return 0;
}

void insertatbeg(){
    int data;
    struct node* temp;
    temp = malloc(sizeof(struct node));
    printf("Enter the number to be inserted at the begining : ");
    scanf("%d",&data);
    temp->data=data;
    temp->next=head;
    head = temp;
}

void insertatend(){
    int data;
    struct node*temp,*ptr;
    temp = malloc(sizeof(struct node));
    printf("Enter the number to be inserted at the ending : ");
    scanf("%d",&data);
    temp->next=NULL;
    temp->data= data;
    ptr = head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;

}
void insertatspec(){
	struct node *temp, *newnode;
	int pos, data, i = 1;
	newnode = malloc(sizeof(struct node));
	printf("\nEnter position : ");
	scanf("%d", &pos);
	printf("\nEnter the data : ");
	scanf("%d", &data);
	temp = head;
	newnode->data = data;
	newnode->next = 0;
	while (i < pos - 1) {
		temp = temp->next;
		i++;
	}
	newnode->next = temp->next;
	temp->next = newnode;
}

void display(){
    struct node*temp;
    if(head==NULL)
        printf("The linked list is Empty !!!");
    else{
        temp = head;
        while (temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp = temp->next;
        }
        
    }

}

void deleteatbeg(){
	struct node* temp;
	if (head == NULL)
		printf("\nThe linked list is Empty !!!");
	else {
        printf("\nThe number %d deleted from the beggining !!", head->data );
		temp = head;
		head = head->next;
	}
}
void deleteatend(){
	struct node *temp, *prevnode;
	if (head == NULL)
		printf("\n The linked list is Empty !!!");
	else {
		temp = head;
		while (temp->next != 0) {
			prevnode = temp;
			temp = temp->next;
		}
		prevnode->next = 0;
        printf("\nThe number %d deleted from the end !!", temp->data);
	}
}
void deleteatspec(){
	struct node *temp, *position;
	int i = 1, pos;
	if (head == NULL)
		printf("\n The linked list is Empty !!!");
	else {
		printf("\nEnter the Position : ");
		scanf("%d", &pos);
		position = malloc(sizeof(struct node));
		temp = head;
		while (i < pos - 1) {
			temp = temp->next;
			i++;
		}
		position = temp->next;
		temp->next = position->next;
        printf("\n !!Deleted from the position %d !!" , pos);
	}
}