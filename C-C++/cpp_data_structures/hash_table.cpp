#include <iostream>

#include <unordered_map>

int main(){

    std::unordered_map<int , int> m = {{3 , 5} , {2 , 6}};

    for(auto i : m){
        std::cout << i.second << " ";
    }
    std::cout << "\n";

    std::cout << m.at(3);

    return 0;
}