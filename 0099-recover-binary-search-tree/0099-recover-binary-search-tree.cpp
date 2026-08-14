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
    TreeNode *first=NULL,*middle=NULL,*last=NULL,*prev=NULL;
    int c=1;
    void help(TreeNode* temp)
    {
        if(temp==NULL) return;
        help(temp->left);
        if(prev!=NULL&&temp->val<prev->val)
        {
            if(first==NULL)
            {
                first=temp;
                middle=prev;
            }
            else
            {
                last=temp;
            }
        }
        prev=temp;
        help(temp->right);
    }
    void recoverTree(TreeNode* root) {
        help(root);
        if(last==NULL) swap(first->val,middle->val);
        else swap(middle->val,last->val);
    }
};