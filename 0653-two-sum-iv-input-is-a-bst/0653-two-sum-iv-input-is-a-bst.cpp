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
    void help(TreeNode *temp,vector<int>&ans)
    {
        if(temp==NULL) return;
        help(temp->left,ans);
        ans.push_back(temp->val);
        help(temp->right,ans);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        help(root,ans);
        int i=0,j=ans.size()-1;
        while(i<j)
        {
            if(ans[i]+ans[j]==k) return true;
            else if(ans[i]+ans[j]>k) j--;
            else i++;
        }
        return false;
    }
};