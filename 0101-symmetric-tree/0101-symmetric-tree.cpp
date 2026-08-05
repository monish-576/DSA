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
    bool ans=true;
    void help(TreeNode *t1,TreeNode *t2)
    {
        if(t1==NULL&&t2==NULL) return;
        if(t1==NULL||t2==NULL||t1->val!=t2->val)
        {
            ans=false;
            return;
        }
        help(t1->left,t2->right);
        help(t1->right,t2->left);
    }
    bool isSymmetric(TreeNode* root) {
       help(root->left,root->right);
       return ans;
    }
};