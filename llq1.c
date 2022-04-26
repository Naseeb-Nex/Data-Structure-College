#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *head1;
struct node *head2;
struct node *ptr;
struct node *new;
void even(int t)
{
    new = malloc(sizeof(struct node));
    new->data = t;
    new->link = NULL;
    if (head1 == NULL)
    {
        head1 = new;
    }
    else
    {
        ptr = head1;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = new;
    }
}
void odd(int t)
{
    new = malloc(sizeof(struct node));
    new->data = t;
    new->link = NULL;
    if (head2 == NULL)
    {
        head2 = new;
    }
    else
    {
        ptr = head2;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = new;
    }
}
void merge()
{
    ptr = head1;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = head2;
}
void display()
{
    ptr = head1;
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->link;
    }
}
// void sort()
// {
//     struct node *ptr1, *ptr2, *prev, *next;
//     ptr1 = head1;
//     ptr2 = head1;
//     int temp, value = 0;
//     while (ptr1 != NULL)
//     {
//         while (ptr2 != NULL)
//         {
//             if (ptr->data == value)
//             {
//                 break;
//             }
//             else
//             {
//                 next = ptr->link;
//                 if (ptr2->data > next->data)
//                 {
//                     temp = ptr2->data;
//                     ptr2->data = next->data;
//                     next->data = temp;
//                 }
//                 printf("Looping");
//                 prev = ptr2;
//                 ptr2 = ptr2->link;
//             }
//         }
//         value = prev->data;
//         printf("error");
//         ptr1 = ptr1->link;
//     }
// }

void bubbleSort()
{
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;
  
    /* Checking for empty list */
    if (head1 == NULL)
        return;
  
    do
    {
        swapped = 0;
        ptr1 = head1;
  
        while (ptr1->link != lptr)
        {
            if (ptr1->data > ptr1->link->data)
            { 
                swap(ptr1, ptr1->link);
                swapped = 1;
            }
            ptr1 = ptr1->link;
        }
        lptr = ptr1;
    }
    while (swapped);
}
  
/* function to swap data of two nodes a and b*/
void swap(struct node *a, struct node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
int main()
{
    int n, x, a[10], b[10];

    printf("enter the no of terms in even add odd nodes\n");
    scanf("%d", &n);
    printf("\nenter even\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        even(x);
    }

    printf("\nenter odd\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        odd(x);
    }

    merge();
    bubbleSort();
    display();
}