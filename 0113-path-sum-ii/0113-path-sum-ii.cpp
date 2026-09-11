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
    void help(TreeNode* temp,int target,vector<vector<int>>&ans,vector<int>&res,int sum)
    {
        if(temp==NULL) return;
        if(temp->left==NULL&&temp->right==NULL)
        {
           res.push_back(temp->val);
           sum+=temp->val;
           if(sum==target) ans.push_back(res);
           sum-=temp->val;
           res.pop_back();
           return;
        }
        res.push_back(temp->val);
        sum+=temp->val;
        help(temp->left,target,ans,res,sum);
        help(temp->right,target,ans,res,sum);
        sum-=temp->val;
        res.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>res;
        help(root,targetSum,ans,res,0);
        return ans;
    }
};