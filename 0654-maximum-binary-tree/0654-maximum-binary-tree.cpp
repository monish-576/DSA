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
    TreeNode* help(vector<int>&nums,int l,int r)
    {
        if(l>r) return NULL;
        int k,maxi=-1;
        for(int i=l;i<=r;i++)
        {
            if(nums[i]>maxi)
            {
                maxi=nums[i];
                k=i;
            }
        }
        TreeNode *head=new TreeNode(nums[k]);
        head->left=help(nums,l,k-1);
        head->right=help(nums,k+1,r);
        return head;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
                return help(nums,0,nums.size()-1);
    }
};