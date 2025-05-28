#include <iostream>

#include <queue>

int main()
{

    std::queue<int> nums;
    nums.push(3);
    nums.push(5);
    nums.push(2);
    nums.push(1);

    std::cout << nums.front() << "\n";

    std::cout<< nums.back()  <<"\n";

    nums.pop();

}