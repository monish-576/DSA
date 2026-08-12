/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* help(TreeNode* temp,TreeNode* p,TreeNode* q)
    {
           if(temp==NULL) return NULL;
           TreeNode *left=help(temp->left,p,q);
           TreeNode *right=help(temp->right,p,q);
           if(temp==p||temp==q) return temp;
           if(left!=NULL&&right!=NULL) return temp;
           return left==NULL? right:left;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return help(root,p,q);
    }
};