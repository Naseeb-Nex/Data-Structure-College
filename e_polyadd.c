#include <stdio.h>

struct poly
{
    int ex;
    int co;
} x1[15], x2[15], x3[30], x4[30];

int input(struct poly x[])
{
    int n, i;
    printf("\nEnter the size of Poly : ");
    scanf("%d", &n);
    printf("\nEnter the values of poly : ");
    for (i = 0; i < n; i++)
    {
        printf("\n Enter the coeff : ");
        scanf("%d", &x[i].co);
        printf(" Enter the expo : ");
        scanf("%d", &x[i].ex);
    }
    return n;
}

void display(struct poly x[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf(" %d X^%d ,", x[i].co, x[i].ex);
    }
}

int add(int n, int m)
{
    int i = 0, k = 0, j = 0;
    while (i < n && j < m)
    {
        if (x1[i].ex > x2[j].ex)
        {
            x3[k].ex = x1[i].ex;
            x3[k].co = x1[i].co;
            i++;
            k++;
        }
        if (x1[i].ex < x2[j].ex)
        {
            x3[k].ex = x2[j].ex;
            x3[k].co = x2[j].co;
            j++;
            k++;
        }
        if (x1[i].ex = x2[j].ex)
        {
            x3[k].ex = x2[j].ex;
            x3[k].co = x1[i].co + x2[j].co;
            j++;
            i++;
            k++;
        }
    }
    while (i < n)
    {
        x3[k].ex = x1[i].ex;
        x3[k].co = x1[i].co;
        i++;
        k++;
    }

    while (j < m)
    {
        x3[k].ex = x2[j].ex;
        x3[k].co = x2[j].co;
        j++;
        k++;
    }
    return k;
}

int mul(int n, int m)
{
    int i, j, k = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            x4[k].co = x1[i].co * x2[j].co;
            x4[k].ex = x1[i].ex + x2[j].ex;
            k++;
        }
    }
    return k;
}

void main()
{
    printf("Enter the first poly");
    int n = input(x1);
    printf("Enter the scond poly : ");
    int m = input(x2);
    display(x1, n);
    display(x2, m);
    int ch;
    char c;
    while (1)
    {
        printf("\n 1. Addition\n 2. Multiplication \nEnter the your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nAddition Result : ");
            int k = add(n, m);
            display(x3, k);
            break;

        case 2:
            printf("\nMultiplication Result : ");
            int d = mul(n, m);
            display(x4, d);

        default:

            break;
        }
        printf("Do you want to continue ? y/n");
        scanf(" %c", &c);
        if (c == 'n')
        {
            break;
        }
    }
}