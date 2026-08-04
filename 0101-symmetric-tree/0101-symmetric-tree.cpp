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
    bool help(TreeNode *t1,TreeNode *t2)
    {
        if(t1==NULL&&t2==NULL)
        return true;
        if(t1==NULL||t2==NULL)
        return false;
        if(t1->val!=t2->val)
        return false;
        bool c1=help(t1->left,t2->right);
        bool c2=help(t1->right,t2->left);
        return c1==true&&c2==true;
    }
    bool isSymmetric(TreeNode* root) {
        return help(root->left,root->right);
    }
};