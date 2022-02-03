// Create a Doubly Linked List from a string taking each character
//  from the string. Check if the given string is palindrome in an efficient method.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data;
    struct node *next;
    struct node *prev;
};

struct node *front = NULL;
struct node *rear = NULL;

void insert(char data);
void check(int l);

int main()
{
    char s[30];

    printf("Enter a Word : ");
    gets(s);
    for (int i = 0; i < strlen(s); i++)
    {
        insert(s[i]);
    }
    check(strlen(s));
    return 0;
}

void insert(char data)
{
    struct node *ptr, *temp;
    ptr = malloc(sizeof(struct node));
    ptr->data = data;
    if (front == NULL && rear == NULL)
    {
        ptr->next = NULL;
        ptr->prev = NULL;
        front = ptr;
        rear = ptr;
    }
    else
    {
        temp = rear;
        temp->next = ptr;
        ptr->prev = temp;
        ptr->next = NULL;
        rear = ptr;
    }
}
void check(int l)
{
    struct node *last, *first;
    if (front == NULL && rear == NULL)
    {
        printf("Empty");
    }
    else
    {
        first = front;
        last = rear;
        int i = 0, flag = 0;
        while (i < l / 2)
        {
            if (first->data != last->data)
            {
                flag = 1;
                break;
            }
            i++;
            first = first->next;
            last = last->prev;
        }
        if (flag == 0)
        {
            printf("Palindrome");
        }
        else
        {
            printf("Not Palindrome");
        }
    }
}
