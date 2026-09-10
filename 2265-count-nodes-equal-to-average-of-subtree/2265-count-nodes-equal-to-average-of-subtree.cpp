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
    int c=0;
    pair<int,int> help(TreeNode *temp)
    {
        int sum=0,k=0;
        if(temp==NULL) return {sum,k};
       pair<int,int> left=help(temp->left);
       pair<int,int> right=help(temp->right);
       sum+=temp->val+left.first+right.first;
       k+=1+left.second+right.second;
       if(sum/k==temp->val) c++;
         return {sum,k};
    }
    int averageOfSubtree(TreeNode* root) {
        pair<int,int> k=help(root);
        return c;
    }
};