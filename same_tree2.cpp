#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    queue<TreeNode*> queue1, queue2;
    queue1.push(p);
    queue2.push(q);

    while (!queue1.empty() && !queue2.empty()) {
        TreeNode* node1 = queue1.front(); queue1.pop();
        TreeNode* node2 = queue2.front(); queue2.pop();

        if (!node1 && !node2) continue;
        if (!node1 || !node2) return false;
        if (node1->val != node2->val) return false;

        queue1.push(node1->left);
        queue1.push(node1->right);
        queue2.push(node2->left);
        queue2.push(node2->right);
    }

    return queue1.empty() && queue2.empty();
}

int main() {
    TreeNode* a = new TreeNode(1);
    a->left = new TreeNode(2);
    a->right = new TreeNode(3);

    TreeNode* b = new TreeNode(1);
    b->left = new TreeNode(2);
    b->right = new TreeNode(3);

    cout << (isSameTree(a, b) ? "Same Tree (Iterative)" : "Different Trees") << endl;
    return 0;
}
