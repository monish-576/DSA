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
    TreeNode* help(TreeNode* root1,TreeNode* root2)
    {
        if(root1==NULL&&root2==NULL) return NULL;
        TreeNode *root=NULL;
        if(root1!=NULL&&root2!=NULL) 
        {
          root= new TreeNode(root1->val+root2->val);
          root->left=help(root1->left,root2->left);
          root->right=help(root1->right,root2->right);
        }
        else if(root1==NULL)
        {
          root=new TreeNode(root2->val);
          root->left=help(NULL,root2->left);
          root->right=help(NULL,root2->right);
        }
        else
        {
          root=new TreeNode(root1->val);
          root->left=help(root1->left,NULL);
          root->right=help(root1->right,NULL);
        }
        return root;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return help(root1,root2);
    }
};