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
    void help(TreeNode *temp,string ans,vector<string>&res)
    {
        if(temp==NULL)
        {
            return;
        }
        int oldSize = ans.size();
        ans+="->";
        ans+=to_string(temp->val);
        if(temp->left==NULL&&temp->right==NULL)
         res.push_back(ans);
        help(temp->left,ans,res);
        help(temp->right,ans,res);
        ans.resize(oldSize);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        string ans;
        ans+=to_string(root->val);
        if(root->left==NULL&&root->right==NULL)
        return {ans};
        help(root->left,ans,res);
        help(root->right,ans,res);
        return res;
    }
};