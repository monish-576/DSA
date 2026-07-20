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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head->next==NULL) return head;
        ListNode *temp=head;
        int c=0;
        while(temp!=NULL)
        {
            c++;
            temp=temp->next;
        }
        temp=head;
        int back=c-k,i=0;
        while(temp!=NULL&&i<k-1)
        {
            temp=temp->next;
            i++;
        }
        ListNode *start=temp;
        temp=head;
        i=0;
        while(temp!=NULL&&i<back)
        {
            temp=temp->next;
            i++;
        }
        ListNode *end=temp;
        swap(start->val,end->val);
        return head;
    }
};