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
    bool c=true;
    int help1(TreeNode *temp)
    {
        if(temp==NULL) return 0;
        return 1+max(help1(temp->left),help1(temp->right));
    }
    void help(TreeNode *temp)
    {
        if(temp==NULL)
        return ;
        help(temp->left);
        help(temp->right);
        if(abs(help1(temp->left)-help1(temp->right))>1)
        {
            c=false;
        }
    }
    bool isBalanced(TreeNode* root) {
      help(root);
      return c;
    }
};