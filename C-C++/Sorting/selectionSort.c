#include <stdio.h>
#define MAX_SIZE 100

int size;
int array[MAX_SIZE];

void readInput() {
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
}

void selectionSort() {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
}

void printArray() {
    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    readInput();
    selectionSort();
    printArray();

    return 0;
}