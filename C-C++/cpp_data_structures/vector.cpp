#include <iostream>

#include <vector>
#include <algorithm>
void print(std::vector<int> num)
{
    std::cout << "Vector elements are : \n ";
    for (int n : num)
    {
        std::cout << n << " ";
    }
    std::cout << "\n";
}
int main()
{

    // std::vector<int> num = {2, 4, 5, 8, 1, 2, 7};
    // print(num);
    // // add a number 5 at the end
    // num.push_back(5);
    // print(num);
    // // pop a number from the end
    // num.pop_back();
    // print(num);

    // // first element
    // std::cout << num[0] << "\n";

    // // last element
    // std::cout << num[num.size() - 1] << "\n";

    // // sort the vector
    // std::sort(num.begin(), num.end());
    // print(num);

    // // erase elements
    // num.erase(num.begin() + 3, num.end());
   
    // print(num);

    std::vector<int> *v = new std::vector<int>;

    v->push_back(5);
    v->push_back(6);
    v->push_back(4);

    delete v;

    return 0;
}
