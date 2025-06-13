#include <iostream>

#include <queue>
int main(){
    std::queue<int> q;
    int visited[7] = {0,0,0,0,0,0,0};

    int g[7][7] ={
        {0,1,1,1,0,0,0},
        {1,0,1,1,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,0,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,1},
    } ;

    std::cout<<"i : "<<0<<" ";
    q.push(0);
    visited[0] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i = 0 ; i < 7 ; i++){
            if((g[node][i] == 1) && (visited[i] == 0)){
                q.push(i);
                visited[i] = 1;
                std::cout<<i<<" ";
            }
        }
    }

    
    return 0;
}