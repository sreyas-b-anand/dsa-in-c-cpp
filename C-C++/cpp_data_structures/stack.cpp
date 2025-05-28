#include <iostream>

#include <stack>

int main()
{
    std::stack<int> nums;

    nums.push(9);
    nums.push(5);
    nums.pop();
    std::cout << nums.top();

    return 0;
}