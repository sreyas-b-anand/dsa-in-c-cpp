#include <stdio.h>
int item, size;
void renameArray(int array[]) {
    int  i;
    printf("\nEnter the size of array: ");
    scanf("%d", &size);
    printf("Enter the array elements: ");
    for (i=0; i<size; i++) {
        scanf("%d", &array[i]);
    }
    printf("Enter the items to be searched: ");
    scanf("%d", &item); 
}
void linearSearch(int array[]) {
    for (int i=0; i<size; i++) {
        if (item == array[i]) {
            printf("\nElement found at position %d\n", i+1);
            return;
        }
    }
    printf("Element not found!\n");
}
void main() {
    int array[10];
    renameArray(array);
    linearSearch(array);
}