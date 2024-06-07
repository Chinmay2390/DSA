// merge_sorted_lists.cpp - Merge two sorted linked lists
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* a = new ListNode(1);
    a->next = new ListNode(3);
    a->next->next = new ListNode(5);

    ListNode* b = new ListNode(2);
    b->next = new ListNode(4);
    b->next->next = new ListNode(6);

    ListNode* merged = mergeTwoLists(a, b);
    printList(merged);

    return 0;
}
