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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans=1;
        if(root->left==NULL&&root->right==NULL) return ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            long long size=q.size();
            long long min=q.front().second;
            long long first,last;
            for(int i=0;i<size;i++)
            {
                TreeNode *temp=q.front().first;
                long long curr=q.front().second-min;
                q.pop();
                if(i==0) first=curr;
                if(i==size-1) last=curr;
                if(temp->left!=NULL)
                q.push({temp->left,2*curr+1});
                if(temp->right!=NULL)
                q.push({temp->right,2*curr+2});
            }
            ans=max(ans,last-first+1);
        }
        return (int)ans;
    }
};