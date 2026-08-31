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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>arr;
        int i=1;
        ListNode *temp=head->next;
        if(temp->next==NULL) return {-1,-1};
        ListNode *prev=head;
        while(temp->next!=NULL)
        {
            i++;
            if((temp->val>temp->next->val&&temp->val>prev->val)||(temp->val<temp->next->val&&temp->val<prev->val))
            arr.push_back(i);
            prev=prev->next;
            temp=temp->next;
        }
        int n=arr.size();
        if(n<2) return {-1,-1};
        int j=INT_MAX;
        for(int i=1;i<n;i++)
        {
            j=min(j,arr[i]-arr[i-1]);
        }
        return {j,arr[n-1]-arr[0]};
    }
};