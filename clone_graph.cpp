// clone_graph.cpp - Deep copy of a graph using DFS
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() : val(0), neighbors() {}
    Node(int _val) : val(_val), neighbors() {}
    Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};

Node* cloneDFS(Node* node, unordered_map<Node*, Node*>& visited) {
    if (!node) return nullptr;

    if (visited.count(node)) return visited[node];

    Node* clone = new Node(node->val);
    visited[node] = clone;

    for (Node* neighbor : node->neighbors)
        clone->neighbors.push_back(cloneDFS(neighbor, visited));

    return clone;
}

Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> visited;
    return cloneDFS(node, visited);
}

int main() {
    // Test: Create a 2-node graph
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    node1->neighbors.push_back(node2);
    node2->neighbors.push_back(node1);

    Node* cloned = cloneGraph(node1);
    cout << "Original: " << node1->val << ", Cloned: " << cloned->val << endl;
    return 0;
}
