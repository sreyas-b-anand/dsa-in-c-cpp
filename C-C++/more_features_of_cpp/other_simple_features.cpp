#include <iostream>

inline int square(int x){
    return x * x;
}

int main(){

    register int num = 10;
    std::cout << square(num);
    return 0;
}