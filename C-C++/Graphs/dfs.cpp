#include <iostream>

int visited[7] = {0, 0, 0, 0, 0, 0, 0};

int g[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 1, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
};

void dfs(int i){
    for(int j = 0 ; j < 7 ;j++){
        if(g[i][j] == 1 && visited[j]==0){
            std::cout<<j<<" ";
            visited[j]=1;
            dfs(j);
        }
    }
}

int main()
{
    std::cout<<0<<" ";
    visited[0]=1;
    dfs(0);

    return 0;
}
