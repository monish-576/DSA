class Solution {
public:
    void dfs(int idx,vector<vector<int>>&graph,vector<int>&res,vector<vector<int>>&ans,vector<int>&vis)
    {
        vis[idx]=1;
        res.push_back(idx);
        if(idx==graph.size()-1)
        {
            ans.push_back(res);
        }
        for(int i=0;i<graph[idx].size();i++)
        {
            if(vis[graph[idx][i]]==-1)
            {
                dfs(graph[idx][i],graph,res,ans,vis);
                vis[graph[idx][i]]=-1;
                res.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>ans;
        vector<int>res;
        vector<int>vis(n,-1);
        dfs(0,graph,res,ans,vis);
        return ans;
    }
};