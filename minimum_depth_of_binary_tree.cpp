// minimum_depth_of_binary_tree.cpp - Find minimum depth of binary tree
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int minDepth(TreeNode* root) {
    if (!root) return 0;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 1});

    while (!q.empty()) {
        auto [node, depth] = q.front(); q.pop();

        if (!node->left && !node->right)
            return depth;

        if (node->left) q.push({node->left, depth + 1});
        if (node->right) q.push({node->right, depth + 1});
    }

    return 0;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    cout << "Minimum Depth: " << minDepth(root) << endl;
    return 0;
}
