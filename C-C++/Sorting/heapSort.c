#include <stdio.h>

void heapify(int a[], int index, int n)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;
    if (left < n && a[largest] < a[left])
    {
        largest = left;
    }
    if (right < n && a[largest] < a[right])
    {
        largest = right;
    }
    if (largest != index)
    {
        int temp = a[index];
        a[index] = a[largest];
        a[largest] = temp;
        heapify(a, largest, n);
    }
    
}
void maxHeap(int a[], int size)
{
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        heapify(a, i, size);
    }
}
void heapSort(int a[], int size)
{
    maxHeap(a, size);

    for (int i = size - 1; i >= 0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, 0, i);
    }
}
int main()
{
    int ar[] = {4, 7, 2, 6, 1, 9, 7};
    int n = sizeof(ar) / sizeof(ar[0]);
    heapSort(ar, n);
    for (int i = 0; i < n; i++){
        printf("%d ", ar[i]);
    }
    return 0;
}