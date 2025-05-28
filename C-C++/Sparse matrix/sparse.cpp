#include <iostream>

int read(int a[][20])
{
    int r, c;
    std::cout << "Enter the row and column size of the matrix";
    std::cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            std::cout << "enter element " << i << " " << j;
            std::cin >> a[i][j];
        }
    }
    return r;
}
int sparseConversion(int a[][20], int b[][20], int r, int c)
{
    b[0][0] = r;
    b[0][1] = c;
    int k = 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++, k++)
        {
            if (a[i][j] != 0)
            {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
            }
        }
    }
    b[0][2] = k;
    return k+1;
}

void display(int a[][20], int r)
{
    std::cout << "Sparse matrix is...";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << " ";
    }
}

int main()
{
    int arr[20][20] , b[20][20];
    int r1 = read(arr);
    int k1 = sparseConversion(arr , b , r1 , 4);
    display(b , k1);
    return 0;
}