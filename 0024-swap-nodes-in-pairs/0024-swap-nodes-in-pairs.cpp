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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        vector<int>res1,res2;
        int c=0;
        ListNode *temp=head;
        while(temp!=NULL)
        {
            if(c%2==0)
            res1.push_back(temp->val);
            else
            res2.push_back(temp->val);
            temp=temp->next;
            c++;
        }
        ListNode *t=NULL,*res=NULL;
        int i=0,j=0;
        c=0;
        while(i<res1.size()&&j<res2.size())
        { 
            if(c%2==0)
            {
               ListNode *newnode=new ListNode(res2[j]);
               if(t==NULL)
               {
                 t=newnode;
                 res=newnode;
               }
               else
               {
                t->next=newnode;
                t=newnode;
               }
               j++;
            }
            else
            {
                ListNode *newnode=new ListNode(res1[i]);
                 if(t==NULL)
                  {
                    t=newnode;
                    res=newnode;
                  }
                 else
                  {
                   t->next=newnode;
                   t=newnode;
                  }
                i++;
            }
            c++;
        }
        while(i<res1.size())
        {
              ListNode *newnode=new ListNode(res1[i]);
                 if(t==NULL)
                  {
                    t=newnode;
                    res=newnode;
                  }
                 else
                  {
                   t->next=newnode;
                   t=newnode;
                  }
                i++;
        }
        while(j<res2.size())
        {
             ListNode *newnode=new ListNode(res2[j]);
               if(t==NULL)
               {
                 t=newnode;
                 res=newnode;
               }
               else
               {
                t->next=newnode;
                t=newnode;
               }
               j++;
        }
         return res;
    }
};