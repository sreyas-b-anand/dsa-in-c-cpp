#include <iostream>
#include <vector>
#include <stack>

void dfs(int v, const std::vector<std::vector<int>> &adj, std::vector<bool> &visited, std::stack<int> &orderings) {
    visited[v] = true;
    for (int nei : adj[v]) {
        if (!visited[nei]) {
            dfs(nei, adj, visited, orderings);
        }
    }
    orderings.push(v); 
}

void topSort(const std::vector<std::vector<int>> &adj) {
    int n = adj.size();
    std::vector<bool> visited(n, false);
    std::stack<int> orderings;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, adj, visited, orderings);
        }
    }
    while(!orderings.empty()){
        int v = orderings.top();
        orderings.pop();
        std::cout << v << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<std::vector<int>> G = {
        {1, 2}, {4}, {3}, {1}, {}
    };

    topSort(G);
    return 0;
}
