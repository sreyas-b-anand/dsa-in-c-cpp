#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;
void print(vector<pair<int , int>> &vector){
for(auto pair : vector){
        cout << pair.first << " " << pair.second << "\n";
    }
}
int main(){
    vector<pair<int , int>> vector;
    for(int i = 0 ; i < 6 ; i++){
        vector.emplace_back(i , i*4 * i - 2 * (i - 3)*5);
    } 
    print(vector);
    cout<<"\n****************************\n";
    sort(vector.begin() , vector.end() , [](const auto &p1 , const auto &p2){ return p1.second > p2.second; });//custom cmps
    print(vector);


    return 0;
}