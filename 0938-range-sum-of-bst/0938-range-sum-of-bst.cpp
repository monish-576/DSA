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
    void help(TreeNode *temp,int low,int high)
    {
        if(temp==NULL) return;
        help(temp->left,low,high);
        if(temp->val>=low&&temp->val<=high)
        ans+=temp->val;
        help(temp->right,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        help(root,low,high);
        return ans;
    }
};