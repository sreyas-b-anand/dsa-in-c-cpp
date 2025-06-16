#include <iostream>
#include <vector>

#define SIZE 6

std::vector<int> parent = {0, 1, 2, 3, 4, 5};
std::vector<int> rank(SIZE, 0);

int find(int x)
{
    if (x != parent[x])
    {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}
void unionSet(int x, int y)
{
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY)
        std::cout<<"There is a cycle "<<rootX <<" "<<rootY;
    if (rank[rootX] < rank[rootY])
    {
        parent[rootX] = rootY;
    }
    else if (rank[rootX] > rank[rootY])
    {
        parent[rootY] = rootX;
    }
    else
    {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}
int main()
{
    int edges[5][2] = {
        {0, 1},
        {0, 2},
        {2 ,3},
        {3, 4},
        {3, 5}};

    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        unionSet(u ,v);
    }

    std::cout << "Parent of 5 : " << find(5);
}