#include <stdio.h>

#define MAX_SIZE 100

int size;
int array[MAX_SIZE];

void readInput()
{
    printf("Enter the size of the array : ");
    scanf("%d", &size);
    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
}

void insertionSort()
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void printArray()
{
    printf("Sorted array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    readInput();
    insertionSort();
    printArray();

    return 0;
}