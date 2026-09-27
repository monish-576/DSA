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
    int ans=0;
    void help(TreeNode* temp)
    {
        if(temp==NULL) return;
        if(temp->val%2==0)
        {
            if(temp->left!=NULL)
            {
                if(temp->left->left!=NULL)
                ans+=temp->left->left->val;
                if(temp->left->right!=NULL)
                ans+=temp->left->right->val;
            }
            if(temp->right!=NULL)
            {
                if(temp->right->left!=NULL)
                ans+=temp->right->left->val;
                if(temp->right->right!=NULL)
                ans+=temp->right->right->val;
            }
        }
        help(temp->left);
        help(temp->right);
    }
    int sumEvenGrandparent(TreeNode* root) {
        help(root);
        return ans;
    }
};