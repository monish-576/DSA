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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty())
        {
            int n=q.size();
            int prev=-1;
            for(int i=0;i<n;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
                if(level%2==0)
                {
                    if(temp->val%2==0) return false;
                   if(prev==-1) prev=temp->val;
                   else
                   {
                      if(temp->val>prev)
                      {
                         prev=temp->val;
                      }
                      else return false;
                   }
                }
                else
                {
                   if(temp->val%2!=0) return false;
                   if(prev==-1) prev=temp->val;
                   else
                   {
                      if(temp->val<prev)
                      {
                         prev=temp->val;
                      }
                      else return false;
                   }
                }
            }
            level++;
        }
        return true;
    }
};