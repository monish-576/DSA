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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *t=NULL,*k=NULL;
        int carry = 0;

        while(l1!=NULL || l2!=NULL)
        {
            int a = carry;

            if(l1!=NULL){
                a += l1->val;
                l1 = l1->next;
            }

            if(l2!=NULL){
                a += l2->val;
                l2 = l2->next;
            }

            int b = a % 10;
            carry = a / 10;

            ListNode *newnode=new ListNode(b);

            if(t==NULL)
            { 
                t=newnode;
                k=t;
            }
            else
            {
                t->next=newnode;
                t=newnode;
            }
        }
        if(carry)
        {
            ListNode *newnode = new ListNode(carry);
            t->next = newnode;
        }

        return k;
    }
};