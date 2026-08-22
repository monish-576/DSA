class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
          vector<int>ans;
          queue<int>q;
          vector<vector<int>>adj(graph.size());
          vector<int>inorder(graph.size(),0);
          for(int i=0;i<graph.size();i++)
          {
             inorder[i]=graph[i].size();
             for(int j=0;j<graph[i].size();j++)
             {
                 adj[graph[i][j]].push_back(i);
             }
          }
          for(int i=0;i<inorder.size();i++)
          {
             if(inorder[i]==0) q.push(i);
          }
          while(!q.empty())
          {
             int i=q.front();
             q.pop();
             ans.push_back(i);
             for(int j=0;j<adj[i].size();j++)
             {
                inorder[adj[i][j]]--;
                if(inorder[adj[i][j]]==0)
                q.push(adj[i][j]);
             }
          }
          sort(ans.begin(),ans.end());
          return ans;
    }
};