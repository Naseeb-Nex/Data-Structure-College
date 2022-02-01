#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head;

void enqueue();
void dequeue();
void display();

int main()
{
    int ch;
    char c;

    while (1)
    {
        printf("**************************\n********Queue using Linked List*******\n**********Menu************\n 1.ENQUEUE\n 2.DEQUEUE\n 3.DISPLAY\n**************************\nEnter your choice : ");
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
            printf("!! Enter a valid input !!");
            break;
        }
        printf("\nDo you want to continue y/n ?");
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
        printf("!!  Memory UnderFLow  !!\n!! No insertion !!");
    else
    {
        printf("Enter the Number : ");
        scanf("%d", &data);
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->data = data;
    }
}

void dequeue()
{
    printf("working");
}

void display()
{
    struct node *temp;
    temp = head;
    if (temp == NULL)
    {
        printf("UnderFlow");
    }
    else
    {
        while (temp == NULL)
        {
            printf(" %d\n", temp->data);
            temp = temp->next;
        }
    }
}