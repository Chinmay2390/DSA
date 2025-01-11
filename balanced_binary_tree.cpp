// balanced_binary_tree.cpp - Check if a binary tree is height-balanced
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int checkHeight(TreeNode* root) {
    if (!root) return 0;

    int left = checkHeight(root->left);
    if (left == -1) return -1;

    int right = checkHeight(root->right);
    if (right == -1) return -1;

    if (abs(left - right) > 1) return -1;

    return max(left, right) + 1;
}

bool isBalanced(TreeNode* root) {
    return checkHeight(root) != -1;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(4);

    cout << (isBalanced(root) ? "Balanced" : "Not Balanced") << endl;
    return 0;
}
