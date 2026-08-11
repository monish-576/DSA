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
    TreeNode *target;
    void help(TreeNode* temp,int start)
    {
        if(temp==NULL)
        return;
        if(temp->val==start)
        {
            target=temp;
        }
        help(temp->left,start);
        help(temp->right,start);
    }
    void help1(TreeNode* temp,unordered_map<TreeNode*,TreeNode*>&mp)
    {
        queue<TreeNode*>q;
        q.push(temp);
        while(!q.empty())
        {
            TreeNode *curr=q.front();
            q.pop();
            if(curr->left!=NULL)
            {
                q.push(curr->left);
                mp[curr->left]=curr;
            }
            if(curr->right!=NULL)
            {
                q.push(curr->right);
                mp[curr->right]=curr;
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        help(root,start);
        unordered_map<TreeNode*,TreeNode*>mp;
        help1(root,mp);
        unordered_map<TreeNode*,bool>vis;
        int level=0;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode *curr=q.front();
                q.pop();
                if(curr->left!=NULL&&!vis[curr->left])
                {
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right!=NULL&&!vis[curr->right])
                {
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(mp.find(curr)!=mp.end()&&!vis[mp[curr]])
                {
                    q.push(mp[curr]);
                    vis[mp[curr]]=true;
                }
            }
            level++;
        }
        return level-1;
    }
};