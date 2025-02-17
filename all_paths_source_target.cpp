// all_paths_source_target.cpp - DFS to find all paths in a DAG from node 0 to n-1
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& graph, int node, vector<int>& path, vector<vector<int>>& result) {
    path.push_back(node);
    if (node == graph.size() - 1) {
        result.push_back(path);
    } else {
        for (int next : graph[node]) {
            dfs(graph, next, path, result);
        }
    }
    path.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> result;
    vector<int> path;
    dfs(graph, 0, path, result);
    return result;
}

int main() {
    vector<vector<int>> graph = {{1,2}, {3}, {3}, {}};
    vector<vector<int>> result = allPathsSourceTarget(graph);

    for (auto& path : result) {
        for (int node : path) cout << node << " ";
        cout << "\n";
    }
    return 0;
}
