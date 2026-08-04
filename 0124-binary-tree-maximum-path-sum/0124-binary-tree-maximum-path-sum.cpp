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
    int ans=INT_MIN;
    int help(TreeNode *root)
    {
        if(root==NULL) return 0;
        int left=root->val+help(root->left),right=root->val+help(root->right);
        int x=max({root->val,left,right});
        ans=max({x,ans,left+right-root->val});
        return x;
    }
    int maxPathSum(TreeNode* root) {
      int c=help(root);
      return ans;
    }
};