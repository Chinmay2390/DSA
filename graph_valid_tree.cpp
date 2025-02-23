// graph_valid_tree.cpp - Check if undirected graph is a valid tree
#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    if (visited[node]) return false;
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (neighbor == parent) continue;
        if (!dfs(neighbor, node, adj, visited)) return false;
    }

    return true;
}

bool validTree(int n, vector<vector<int>>& edges) {
    if (edges.size() != n - 1) return false;

    vector<vector<int>> adj(n);
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<bool> visited(n, false);
    if (!dfs(0, -1, adj, visited)) return false;

    for (bool v : visited) if (!v) return false;
    return true;
}

int main() {
    int n = 5;
    vector<vector<int>> edges = {{0,1},{0,2},{0,3},{1,4}};
    cout << (validTree(n, edges) ? "Valid Tree" : "Not a Tree") << endl;
    return 0;
}
