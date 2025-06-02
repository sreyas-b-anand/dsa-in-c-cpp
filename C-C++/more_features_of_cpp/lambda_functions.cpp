#include <iostream>

int main()
{
    int z = 10;
    auto new_value = [z](int x) { // lambda function to calculate square of a number
        return x * x + z;      // copy of z is in the lambda | even if z changes below this line,  10 is still used here
    };
    z = 20; // value of z will be 10 for the lambda func

    std::cout << new_value(5); // returns 35
    return 0;
}