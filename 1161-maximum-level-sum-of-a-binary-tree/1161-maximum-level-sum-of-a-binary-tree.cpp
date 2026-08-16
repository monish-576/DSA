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
    int maxLevelSum(TreeNode* root) {
        int ans,sum=INT_MIN;
        queue<TreeNode*>q;
        q.push(root);
        int level=1;
        while(!q.empty())
        {
            int n=q.size();
            int curr=0;
            for(int i=0;i<n;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                curr+=temp->val;
                if(temp->left!=NULL)
                q.push(temp->left);
                if(temp->right!=NULL)
                q.push(temp->right);
            }
            if(curr>sum)
            {
                sum=curr;
                ans=level;
                cout<<ans;
            }
            level++;
        }
        return ans;
    }
};