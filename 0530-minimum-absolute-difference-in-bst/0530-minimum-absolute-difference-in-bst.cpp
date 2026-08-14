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
    int getMinimumDifference(TreeNode* root) {
        vector<int>ans;
        help(root,ans);
        int res=INT_MAX;
        for(int i=1;i<ans.size();i++)
        {
            res=min(abs(ans[i]-ans[i-1]),res);
        }
        return res;
    }
};