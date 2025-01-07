// remove_linked_list_elements.cpp - Remove nodes with target value
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeElements(ListNode* head, int val) {
    while (head && head->val == val) head = head->next;
    ListNode* curr = head;
    while (curr && curr->next) {
        if (curr->next->val == val)
            curr->next = curr->next->next;
        else
            curr = curr->next;
    }
    return head;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(6);

    int val = 6;
    head = removeElements(head, val);

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}
