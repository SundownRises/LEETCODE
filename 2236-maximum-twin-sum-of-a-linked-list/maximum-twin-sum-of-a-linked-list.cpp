/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> nodes;
        ListNode* temp = head;
        while (temp != nullptr) {
            nodes.push_back(temp->val);
            temp = temp->next;
        }
        
        int maxTwinSum = 0;
        int n = nodes.size();
        for (int i = 0; i < n / 2; ++i) {
            int twinSum = nodes[i] + nodes[n - 1 - i];
            maxTwinSum = max(maxTwinSum, twinSum);
        }
        
            return maxTwinSum;
    }
};