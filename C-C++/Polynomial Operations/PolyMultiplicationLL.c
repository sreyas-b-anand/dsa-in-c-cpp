#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};
struct Node *Phead = NULL, *Qhead = NULL, *Rhead = NULL, *new = NULL, *newnode, *P, *Q, *R, *prev, *temp , *t;
struct Node *createNode(int coeff, int exp)
{
    new = (struct Node *)malloc(sizeof(struct Node));
    new->coeff = coeff;
    new->exp = exp;
    new->next = NULL;

    return new;
}
void createPolynomial( int n, int p)
{
    int data1 , data2;
    for (int i = 0; i < n; i++)
    {
        printf("Enter coefficient and exponent of term %d: " , i+1);
        scanf("%d %d", &data1, &data2);
        newnode = createNode(data1, data2);
        if (p == 1)
        {
            if (Phead == NULL)
            {
                Phead = P = newnode;
            }
            else
            {
                P->next = newnode;
                P = P->next;
            }
        }
        else if (p == 2)
        {
            if (Qhead == NULL)
            {
                Qhead = Q = newnode;
            }
            else
            {
                Q->next = newnode;
                Q = Q->next;
            }
        }
    }
}
void polyMultiply()
{
    P = Phead, Q = Qhead;
    int d1, d2;
    while (P != NULL)
    {
        while (Q != NULL)
        {
            d1 = P->coeff * Q->coeff;
            d2 = P->exp + Q->exp;
            newnode = createNode(d1, d2);
            if (Rhead == NULL)
            {
                Rhead = R = newnode;
            }
            else
            {
                R->next = newnode;
                R = R->next;
            }
            Q = Q->next;
        }
        Q = Qhead;
        P = P->next;
    }
}
void optimalPolynomial()
{
    R = Rhead;
    while (R != NULL)
    {
        t = R->next;
        prev = R;
        while (t != NULL)
        {
            if (R->exp == t->exp)
            {
                R->coeff = R->coeff + t->coeff;
                prev->next = t->next;
                t->next = NULL;
                free(t);
                t = prev->next;
            }
            else
            {
                t = t->next;
                prev = prev->next;
            }
        }
       
        R = R->next;
    }
}
void printPoly(struct Node *root)
{

    while (root != NULL)
    {
        printf("%dx^(%d) + ", root->coeff, root->exp);
        root = root->next;
    }
}
void main()
{
    int n1, n2;
    printf("\nEnter the no of terms in polynomial 1 : ");
    scanf("%d", &n1);
    createPolynomial(n1 , 1 );
    printf("Polynomial 1 \n");
    printPoly(Phead);
    printf("\nEnter the no of terms in polynomial 2 : ");
    scanf("%d", &n2);
    createPolynomial(n2 ,2);
    printf("\nPolynomial 2 \n");
    printPoly(Qhead);
    polyMultiply();
    optimalPolynomial();
    printf("\nPolynomial 3 \n");
    printPoly(Rhead);
}