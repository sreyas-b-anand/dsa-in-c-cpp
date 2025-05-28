#include <stdio.h>

void merge(int a[], int b[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }

    for (i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

void mergeSort(int a[], int b[], int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    mergeSort(a, b, low, mid);
    mergeSort(a, b, mid + 1, high);

    merge(a, b, low, mid, high);
}

int main()
{
    int b[10];
    int ar[] = {4, 7, 2, 6, 1, 9, 0};
    int n = sizeof(ar) / sizeof(ar[0]);

    mergeSort(ar, b, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }

    return 0;
}
