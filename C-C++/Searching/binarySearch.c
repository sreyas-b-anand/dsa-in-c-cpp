#include <stdio.h>
int item, size;
void readArray(int array[])
{
    int i;
    printf("\nEnter the size of array: ");
    scanf("%d", &size);
    printf("Enter the array elements: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Enter the item to be searched: ");
    scanf("%d", &item);
}
int binarySearch(int array[])
{
    int left = 0, right = size - 1;
    int mid;
    while (left <= right)
    {
        mid = (right + left) / 2;
        if (array[mid] == item)
        {

            return 1;
        }
        else if (array[mid] > item)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return 0;
}
void main()
{
    int array[10], flag;
    readArray(array);
    flag = binarySearch(array);
    if (flag == 1)
    {
        printf("Element found\n");
    }
    else
    {
        printf("Element not found\n");
    }
}