#include <iostream>
#include <set>

int main()
{
    std::set<int> num={9,4, 4 , 5, 6, 7,8 , 8};

    for(int i : num){
        std::cout << i << " ";
    }
    std::cout << "\n";
    auto res = num.insert(499);
    std::cout<<"\n";
    std::cout <<"result "<< res.second << "\n";

    for(int i : num){
        std::cout << i << " ";
    }

    // std::set<int , std::greater<int>> *s = new std::set<int , std::greater<int>>;

    // s->insert(5);
    // s->insert(6);
    // s->insert(7);
    // s->insert(8);
    // s->insert(3);

    // for (auto i : *s)
    // {
    //     std::cout << i << " ";
    // }
    // delete s;
    return 0;
}