#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int number;
    char name[30];
    int totalmark;
    struct node *next;
};
struct node *head = NULL;
void display();
void insert();
void delete();
void search();
int main()
{
    int choice;
    char ch;
    while (1)
    {
        printf("**************************\n*****Student Details******\n**********Menu************\n1.Insert \n2.Delete\n3.Search\n4.Display\n**************************\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            search();
            break;
        case 4:
            display();
            break;
        default:
            printf("Enter a valid choice !!\n");
        }
        printf("\nDo you want to continue y/n ?");
        scanf(" %c", &ch);
        if (ch == 'n')
        {
            break;
        }
    }
    return 0;
}

void insert()
{
    int no, mark;
    char s[30];
    struct node *temp, *ptr;
    temp = malloc(sizeof(struct node));
    printf("Enter the Roll No : ");
    scanf("%d", &no);
    printf("Enter Name : ");
    scanf("%s", s);
    printf("Enter Total mark : ");
    scanf("%d", &mark);
    temp->number = no;
    strcpy(temp->name, s);
    temp->totalmark = mark;
    temp->next = NULL;
    ptr = head;
    if (ptr == NULL)
    {
        head = temp;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void delete ()
{
    struct node *curr, *prev;
    int i = 1, pos = 1, no;
    if (head == NULL)
        printf("\n Empty List");
    else
    {
        printf("\nEnter Roll No : ");
        scanf("%d", &no);

        prev = malloc(sizeof(struct node));
        curr = malloc(sizeof(struct node));
        prev = curr = head;
        while ((curr->next != NULL) && (curr->number != no) )
        {
            printf("1");
            prev = curr;
            curr = curr->next;
        }
        if((curr->next == NULL) && (curr->number != no))
          printf("\nStudent Not Found!!\n");
        else{
            printf("\n Roll no %d is deleted From the list", curr->number);
            prev->next = curr->next;
        }
    }
}

void search()
{
    struct node *temp;
    int no, flag = 0;
    if (head == NULL)
        printf("\n Empty List");
    else
    {
        printf("\nEnter Roll No : ");
        scanf("%d", &no);

        temp = malloc(sizeof(struct node));
        temp = head;
        while (temp != NULL)
        {
            if (temp->number == no)
            {
                printf("\nStudent Details Found\n Roll no :%d\n Name : %s\n Total mark: %d \n", temp->number, temp->name, temp->totalmark);
                flag = 1;
            }
            temp = temp->next;
        }
        if (flag == 0)
        {
            printf("\n!! Student Is Not Find in This List !!\n");
        }
    }
}

void display()
{
    struct node *temp;
    if (head == NULL)
        printf("\nEmpty List !! \n");
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("\nStudent Details\n Roll no :%d\n Name : %s\n Total mark: %d \n", temp->number, temp->name, temp->totalmark);
            temp = temp->next;
        }
    }
}