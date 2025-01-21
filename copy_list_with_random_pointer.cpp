// copy_list_with_random_pointer.cpp - Deep copy of linked list with random pointers
#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

Node* copyRandomList(Node* head) {
    if (!head) return nullptr;

    unordered_map<Node*, Node*> mp;

    Node* curr = head;
    while (curr) {
        mp[curr] = new Node(curr->val);
        curr = curr->next;
    }

    curr = head;
    while (curr) {
        mp[curr]->next = mp[curr->next];
        mp[curr]->random = mp[curr->random];
        curr = curr->next;
    }

    return mp[head];
}

// Helper for testing (not part of Leetcode submission)
void printList(Node* head) {
    while (head) {
        cout << "Val: " << head->val;
        if (head->random)
            cout << ", Random: " << head->random->val << endl;
        else
            cout << ", Random: null" << endl;
        head = head->next;
    }
}

int main() {
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);

    n1->next = n2; n2->next = n3;
    n2->random = n1;
    n3->random = n2;

    Node* copied = copyRandomList(n1);
    printList(copied);
    return 0;
}
