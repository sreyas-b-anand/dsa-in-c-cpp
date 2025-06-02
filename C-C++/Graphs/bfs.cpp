// bfs implementation
#include <iostream>

#include <queue>
int main(){
    std::queue<int> q;
    //bfs

    int u  , i = 0;
    int visited[7] = {0,0,0,0,0,0,0};

    int g[7][7] ={
        {0,1,1,1,0,0,0},
        {1,0,1,1,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    } ;

    std::cout<<"i "<<i<<"\n";
    visited[i] = 1;
    q.push(i);// push i for exploration
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for (int j = 0; j < 7;j++){
            if(g[node][j]  == 1 && visited[j]==0){
                std::cout<<"i " << j <<"\n";
                visited[j] = 1;
                q.push(j); 
            }
        }
    }

    
    return 0;
}