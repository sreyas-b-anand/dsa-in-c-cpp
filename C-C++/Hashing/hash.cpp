#include <iostream>
#include <vector>
#include <unordered_map>

int main(){
    std::unordered_map <int , int> hashmap;

    std::vector<int> ar = {4, 7, 2, 6, 1, 9, 7};
    int r = 837;
    for(int a : ar){
        hashmap.insert({r++ , a});
    }
    
    for(auto hash : hashmap){
        std::cout<<hash.first << " " << hash.second <<"\n";
    }
}