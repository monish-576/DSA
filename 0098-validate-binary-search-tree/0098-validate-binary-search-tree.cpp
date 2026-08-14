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
    bool help(TreeNode* temp,long long a,long long b)
    {
        if(temp==NULL)
        return true;
        if(temp->val<=a||temp->val>=b) return false;
        bool left=help(temp->left,a,temp->val);
        bool right=help(temp->right,temp->val,b);
        return left&&right;
    }
    bool isValidBST(TreeNode* root) {
        return help(root,LLONG_MIN,LLONG_MAX);
    }
};