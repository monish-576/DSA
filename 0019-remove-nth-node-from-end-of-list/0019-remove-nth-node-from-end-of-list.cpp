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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp=head,*t1=head;
        int k=0;
        while(t1!=NULL)
        {
            k++;
            t1=t1->next;
        }
        if(n==k)
       {
        head=head->next;
        return head;
       }
        n=k-n;
        int p=0;
        while(temp!=NULL)
        {
            p++;
           if(n==p)
           {
             temp->next=temp->next->next;
             break;
           }
           else
           {
            temp=temp->next;
           }
        }
         return head;
    }
};