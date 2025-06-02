#include <iostream>

#include <memory>
#include <vector>

int main(){
    //primitive integer variable
    std::unique_ptr<int> p = std::make_unique<int>(); //handles auto delete ops 

    *p = 10;
    std::cout<<*p;
    
    //array
    int k = 3;
    std::unique_ptr<int[]> p2 = std::make_unique<int[]>(5);
    for(int i = 0 ; i < 5 ; i++){
        p2[i] = k++;
    }
    std::cout<<"\n";

    for(int i = 0 ; i < 5 ; i++){
        std::cout<<p2[i] << " ";
        
    }


    //vector
    std::unique_ptr<std::vector<int>>  p3 = std::make_unique<std::vector<int>>();
    for(int i = 0 ; i < 5 ; i++){
        p3->push_back(k++) ;
    }
    std::cout<<"\n";

    for(int i = 0 ; i < 5 ; i++){
        std::cout<<p3->at(i) << " ";
        
    }



    return 0;
}