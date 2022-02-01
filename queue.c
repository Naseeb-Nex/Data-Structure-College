#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue();
void dequeue();
void display();

int main()
{
    int ch;
    char c;

    while (1)
    {
        printf("\n**************************\n**Queue using Linked List**\n**********Menu************\n 1.ENQUEUE\n 2.DEQUEUE\n 3.DISPLAY\n**************************\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        default:
            printf("\n!! Enter a valid input !!\n");
            break;
        }
        printf("\nDo you want to continue y/n? ");
        scanf(" %c", &c);
        if (c == 'n')
        {
            break;
        }
    }

    return 0;
}

void enqueue()
{
    struct node *temp;
    struct node *ptr;
    int data;
    temp = malloc(sizeof(struct node));
    if (temp == NULL)
        printf("!!  OverFlow  !!\n!! No insertion !!\n");
    else
    {
        printf("Enter the Number : ");
        scanf("%d", &data);
        temp->data = data;
        temp->next = NULL;
        if (front == NULL)
        {
            front = rear = temp;
        }
        else{
            rear->next = temp;
            rear = temp;
        }
        
    }
}

void dequeue()
{
    if (front == NULL)
        printf("\n!!  UnderFlow  !!\n");
    else{
        printf("The element %d is deleted\n", front->data);
        front = front->next;
    }
}

void display()
{
    struct node *temp;
    temp = front;
    if (temp == NULL)
    {
        printf("\n!! The Queue is Empty !!\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf(" %d\n", temp->data);
            temp = temp->next;
        }
    }
}