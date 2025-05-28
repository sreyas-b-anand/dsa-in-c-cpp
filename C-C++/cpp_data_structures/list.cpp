#include <iostream>
#include <list>

void print(std::list<int> nums)
{
    std::cout << "List elements are : \n ";
    for (int n : nums)
    {
        std::cout << n << " ";
    }
    std::cout << "\n";
}

int main()
{
    std::list<int> nums = {2, 5, 4, 6, 7, 9, 8};
    print(nums);
    nums.push_front(4);
    nums.push_back(5);

    print(nums);

    nums.pop_front();
    nums.pop_back();

    print(nums);

        return 0;
}