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
    void help2(TreeNode *temp,vector<int>&n2)
    { 
        if(temp==NULL)
        return;
        help1(temp->left,n2);
        if(temp->left==NULL&&temp->right==NULL)
        n2.push_back(temp->val);
        help1(temp->right,n2);
    }
    void help1(TreeNode *temp,vector<int>&n1)
    { 
        if(temp==NULL)
        return;
        help1(temp->left,n1);
        if(temp->left==NULL&&temp->right==NULL)
        n1.push_back(temp->val);
        help1(temp->right,n1);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>n1,n2;
        help1(root1,n1);
        help2(root2,n2);
        return n1==n2;
    }
};