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
    int ans=INT_MAX,last=-1;
    void help(TreeNode* temp)
    {
        if(temp==NULL) return;
        help(temp->left);
        if(last==-1) last=temp->val;
        else
        {
            ans=min(abs(temp->val-last),ans);
            last=temp->val;
        }
        help(temp->right);
    }
    int getMinimumDifference(TreeNode* root) {
        help(root);
        return ans;
    }
};