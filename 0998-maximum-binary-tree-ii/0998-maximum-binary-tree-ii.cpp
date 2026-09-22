/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void help(TreeNode* temp,vector<int>&ans)
    {
        if(temp==NULL) return;
        help(temp->left,ans);
        ans.push_back(temp->val);
        help(temp->right,ans);
    }
    TreeNode* result(vector<int>&ans,int l,int r)
    {
        if(l>r) return NULL;
        int k,maxi=0;
        for(int i=l;i<=r;i++)
        {
            if(ans[i]>maxi)
            {
                maxi=ans[i];
                k=i;
            }
        }
        TreeNode *head=new TreeNode(ans[k]);
        head->left=result(ans,l,k-1);
        head->right=result(ans,k+1,r);
        return head;
    }
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        vector<int>ans;
        help(root,ans);
        ans.push_back(val);
        return result(ans,0,ans.size()-1);
    }
};