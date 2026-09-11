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
    void help1(TreeNode* temp,int target,long long sum)
    {
        if(temp==NULL) return;
        if(temp->left==NULL&&temp->right==NULL)
        {
            sum+=temp->val;
            if(target==sum) ans++;
            return;
        }
        sum+=temp->val;
        if(sum==target) ans++;
        help1(temp->left,target,sum);
        help1(temp->right,target,sum);
    }
    void  help(TreeNode* temp,int target)
    {
       queue<TreeNode*>q;
       q.push(temp);
       while(!q.empty())
       {
            TreeNode *curr=q.front();
            help1(curr,target,0);
            q.pop();
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
       }
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        help(root,targetSum);
        return ans;
    }
};