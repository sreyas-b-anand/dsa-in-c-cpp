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
void dfs(int i)
{
    int j;
    visited[i] = 1;
    std::cout << "i " << i << "\n";
    for (j = 0 ; j < 7 ; j++){
        if(g[i][j] == 1 && visited[j] == 0){
            dfs(j);
        }

    }
}

int main()
{
    dfs(0);

    return 0;
}
