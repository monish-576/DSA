/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        int x=node->next->val;
        int y=node->val;
        node->val=x;
        node->next->val=y;
        node->next=node->next->next;
    }
};