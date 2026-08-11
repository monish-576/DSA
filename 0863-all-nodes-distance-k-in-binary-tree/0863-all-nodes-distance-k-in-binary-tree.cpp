/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void help(unordered_map<TreeNode*,TreeNode*>&mp,TreeNode *temp)
    {
        queue<TreeNode*>q;
        q.push(temp);
        while(!q.empty())
        {
            TreeNode *k=q.front();
            q.pop();
            if(k->left!=NULL)
            {
                mp[k->left]=k;
                q.push(k->left);
            }
            if(k->right!=NULL)
            {
                mp[k->right]=k;
                q.push(k->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mp;
        help(mp,root);
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int level=0;
        while(!q.empty())
        {
            if(level==k) break;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode *curr=q.front();
                q.pop();
                if(curr->left!=NULL&&!visited[curr->left])
                {
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                if(curr->right!=NULL&&!visited[curr->right])
                {
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                if(mp.find(curr)!=mp.end()&&!visited[mp[curr]])
                {
                    q.push(mp[curr]);
                    visited[mp[curr]]=true;
                }
            }
            level++;
        }
        vector<int>ans;
        while(!q.empty())
        {
            TreeNode *curr=q.front();
            q.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
};