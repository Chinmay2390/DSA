// linked_list_cycle.cpp - Detect cycle in a linked list using Floyd's algorithm
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if (!head || !head->next) return false;

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (slow != fast) {
        if (!fast || !fast->next) return false;
        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}

int main() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b; // Cycle here

    cout << (hasCycle(a) ? "Cycle detected" : "No cycle") << endl;

    return 0;
}
