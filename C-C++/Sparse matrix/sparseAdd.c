#include <stdio.h>

int create(int s[][10], int r, int c)
{
    int v, k = 1;
    s[0][0] = r;
    s[0][1] = c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d ", &v);
            if (v != 0)
            {
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = v;
                 k++;
            }
        }
    }
    s[0][2] = k-1;
     for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d  ", s[i][j]);
        }
        printf("\n");
    }
    return k-1;
}
int sparseAdd(int s1[][10], int s2[][10], int s3[][10], int r, int c, int k1, int k2)
{
    int i = 1, j = 1, k = 0;
    s3[0][0] = r;
    s3[0][1] = c;

    while (i <= k1 && j <= k2)
    {
        if (s1[i][0] == s2[j][0])
        {
            if (s1[i][1] == s2[j][1])
            {
                k++;
                s3[k][0] = s1[i][0];
                s3[k][1] = s1[i][1];
                s3[k][2] = s1[i][2] + s2[j][2];
                i++;
                j++;
            }
            else if (s1[i][1] < s2[j][1])
            {
                k++;
                s3[k][0] = s1[i][0];
                s3[k][1] = s1[i][1];
                s3[k][2] = s1[i][2];
                i++;
            }
            else
            {
                k++;
                s3[k][0] = s2[j][0];
                s3[k][1] = s2[j][1];
                s3[k][2] = s2[j][2];
                j++;
            }
        }
        else if (s1[i][0] < s2[j][0])
        {
            k++;
            s3[k][0] = s1[i][0];
            s3[k][1] = s1[i][1];
            s3[k][2] = s1[i][2];
            i++;
        }
        else
        {
            k++;
            s3[k][0] = s2[j][0];
            s3[k][1] = s2[j][1];
            s3[k][2] = s2[j][2];
            j++;
        }
    }

    while (i <= k1)
    {
        k++;
        s3[k][0] = s1[i][0];
        s3[k][1] = s1[i][1];
        s3[k][2] = s1[i][2];
        i++;
    }

    while (j <= k2)
    {
        k++;
        s3[k][0] = s2[j][0];
        s3[k][1] = s2[j][1];
        s3[k][2] = s2[j][2];
        j++;
    }

    s3[0][2] = k;

    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d  ", s3[i][j]);
        }
        printf("\n");
    }

    return k;
}

int main()
{
    int r1, r2, c1, c2, s1[10][10], s2[10][10], s3[10][10];
    printf("Enter row and column count of matrix 1  \n");
    scanf("%d %d", &r1, &c1);
    printf("Enter row and column count of matrix 2  \n");
    scanf("%d %d", &r2, &c2);
    if (r1 != r2 || c1 != c2)
    {
        printf("Addition not possible");
    }
    else
    {
        printf("Enter elements of matrix 1 \n");
        int k1 = create(s1, r1, c1);
        printf("Enter elements of matrix 2 \n");
        int k2 = create(s2, r2, c2);
        printf("Result\n");
        sparseAdd(s1 , s2 , s3 , r1 , c1 , k1 , k2);
    }
    return 0;
}
