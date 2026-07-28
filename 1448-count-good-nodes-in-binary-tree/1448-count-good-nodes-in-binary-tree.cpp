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
    int c=0;
    void help(TreeNode *temp,int x)
    {
        if(temp==NULL)
        return;
        if(temp->val>=x)
        {
             c++;
             x=max(x,temp->val);
        }
        help(temp->left,x);
        help(temp->right,x);
    }
    int goodNodes(TreeNode* root) {
        help(root->left,root->val);
        help(root->right,root->val);
        return c+1;
    }
};