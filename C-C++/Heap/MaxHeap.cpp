// Building a max heap and inserting values to it

#include <iostream>
#include <vector>
inline void newLine(){
    std::cout<<"\n";
}
int getParent(int index)
{
    return (index - 1) / 2;
}
int getLeft(int index)
{
    return (2 * index) + 1;
}
int getRight(int index)
{
    return (2 * index) + 2;
}
void swap(std::vector<int> &ar, int a, int b)
{
    int temp = ar[a];
    ar[a] = ar[b];
    ar[b] = temp;
}
void maxHeap(std::vector<int> &ar, int value)
{
    ar.push_back(value);
    int size = ar.size();
    int i = size - 1;
    while (i > 0)
    {
        int parent = getParent(i);
        if (ar[parent] < ar[i])
        {
            swap(ar, parent, i);
            i = parent;
        }
        else
        {
            return;
        }
    }
}

void deleteHeap(std::vector<int> &arr, int n)
{
    swap(arr, 0, n - 1);
    int i = 0;
    while(true)
    {
        int largest = i;
        int left = getLeft(i);
        int right = getRight(i);
        if (left < arr.size() && arr[left] > arr[largest])
            largest = left;

        if (right < arr.size() && arr[right] > arr[largest])
            largest = right;
        if (arr[largest] > arr[i])
        {
            swap(arr, largest, i);
            i = largest;
        }
        else{
            return;
        }
    }
}
int main()
{
    std::vector<int> arr;
    for (int i = 0; i < 9; i++)
    {
        std::cout << "Enter a number : ";
        int data;
        std::cin >> data;
        maxHeap(arr, data);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    newLine();
    deleteHeap(arr , arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}