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
        vector<int>res;
        while(head!=NULL)
        {
            res.push_back(head->val);
            head=head->next;
        }
        int i=0,j=res.size()-1;
        int ans=0;
        while(i<j)
        {
            ans=max(res[i]+res[j],ans);
            i++;
            j--;
        }
        return ans;
    }
};