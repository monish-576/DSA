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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL) return root;
        queue<TreeNode*>q1,q2;
        q1.push(root);
        q2.push(root);
        int j=0;
        while(!q1.empty()&&!q2.empty())
        {
            int n=q1.size();
            vector<int>res;
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q1.front();
                q1.pop();
                if(j%2==0) q2.pop();
                res.push_back(temp->val);
                if(temp->left!=NULL) 
                {
                    q1.push(temp->left);
                    q2.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q1.push(temp->right);

                    q2.push(temp->right);
                }
            } 
            if(j%2!=0)
            {
                reverse(res.begin(),res.end());
                int k=0;
                for(int i=0;i<n;i++)
                {
                    TreeNode* temp=q2.front();
                    temp->val=res[k];
                    k++;
                    q2.pop();
                }
            }
            j++;
        }
        return root;
    }
};