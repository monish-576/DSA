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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            TreeNode *curr=q.front().first;
            int ver=q.front().second.first;
            int level=q.front().second.second;
            mp[ver][level].insert(curr->val);
            q.pop();
            if(curr->left!=NULL)
            {
                q.push({curr->left,{ver-1,level+1}});
            }
            if(curr->right!=NULL)
            {
                q.push({curr->right,{ver+1,level+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto v:mp)
        {
            vector<int>res;
            for(auto l:v.second)
            {
                res.insert(res.end(),l.second.begin(),l.second.end());
            }
            ans.push_back(res);
        }
        return ans;
    }
};