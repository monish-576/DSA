/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int>res;
            for(int i=0;i<n;i++)
            {
                Node*temp=q.front();
                res.push_back(temp->val);
                for(int i=0;i<temp->children.size();i++)
                {
                    if(temp->children[i]!=NULL) q.push(temp->children[i]);
                }
                q.pop();
            }
            ans.push_back(res);
        }
        return ans;
    }
};