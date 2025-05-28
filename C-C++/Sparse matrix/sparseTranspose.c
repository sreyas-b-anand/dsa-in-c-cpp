#include <stdio.h>

int create(int s[][10], int r, int c)
{
    printf("Enter the matrix elements\n");
    int v , k = 0;
    s[0][0] = r;
    s[0][1] = c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &v);
            if (v != 0)
            {
                k++;
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = v;
            }
        }
    }
    s[0][2] = k;
    return k;
}
void display(int s[][10], int k)
{
    printf("matrix is \n");
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }
}

int sparseTranspose(int s1[][10], int s2[][10], int k1, int r, int c)
{
    s2[0][0] = c;
    s2[0][1] = r;
    s2[0][2] = k1;
    int k = 1;
    for (int i = 0; i < c; i++)
    {
        for (int j = 1; j <= k1; j++)
        {
            if (s1[j][1] == i)
            {
                s2[k][0] = s1[j][1];
                s2[k][1] = s1[j][0];
                s2[k][2] = s1[j][2];
                k++;
            }
        }
    }
    return k - 1;
}
int main()
{
    int s1[10][10], s2[10][10], r, c;
    printf("Enter the row size and column size of the matrix\n ");
    scanf("%d %d", &r, &c);
    int k1 = create(s1, r, c);
    display(s1, k1);
    int k = sparseTranspose(s1, s2, k1, r, c);
    display(s2, k);
}
