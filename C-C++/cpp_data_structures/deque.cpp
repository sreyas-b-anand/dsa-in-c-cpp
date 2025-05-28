#include <iostream>

#include <deque>

int main()
{

    std::deque<int> nums;
    nums.push_front(3);
    nums.push_back(5);
    nums.push_front(2);
    nums.push_back(1);

    std::cout << nums.front() << "\n";

    std::cout<< nums.back()  <<"\n";

    nums.pop_back();
    nums.pop_front();


}