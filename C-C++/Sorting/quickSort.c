#include <stdio.h>

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    
    while (i <= j)
    {
        while (i <= high && a[i] <= pivot)
            i++;
        while (j >= low && a[j] > pivot)
            j--;
        if (i < j){
            // Swap a[i] and a[j]
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    
    // Swap pivot with a[j]
    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    
    return j; // Return the pivot position
}

void QuickSort(int a[], int l, int h)
{
    if (l < h)
    {
        int j = partition(a, l, h);
        QuickSort(a, l, j - 1);
        QuickSort(a, j + 1, h);
    }
}

int main()
{
    int ar[] = {4, 7, 2, 6, 1};
    int n = sizeof(ar) / sizeof(ar[0]);

    QuickSort(ar, 0, n - 1);
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }
    printf("\n");

    return 0;
}
