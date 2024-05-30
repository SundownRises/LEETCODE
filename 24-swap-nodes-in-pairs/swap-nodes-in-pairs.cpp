
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

    if (!head || !head->next) return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;

    while (head && head->next) {
        ListNode* first = head;
        ListNode* second = head->next;

        first->next = second->next;
        second->next = first;
        prev->next = second;

        prev = first;
        head = first->next;
    }

    ListNode* newHead = dummy->next;
    delete dummy;
    return newHead;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
    
};