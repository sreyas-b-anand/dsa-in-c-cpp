#include <iostream>

#include <map>

int main(){

    std::map<int , int> m = {{3 , 5} , {2 , 6}};

    for(auto i : m){
        std::cout << i.second << " " ;
    }
    
    std::cout<<"\n";
    m.insert({5,7});

    m.erase(2);
    for(auto i : m){
        std::cout << i.second << " ";
    }

    return 0;
}