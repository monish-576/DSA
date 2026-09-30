class Solution {
public:
    bool dfs(int idx,vector<vector<int>>&adj,vector<int>&vis,stack<int>&st)
    {
        vis[idx]=1;
        for(int j=0;j<adj[idx].size();j++)
        {
            if(vis[adj[idx][j]]==0)
            {
                if(!dfs(adj[idx][j],adj,vis,st))
                  return false;
            }
            else if(vis[adj[idx][j]]==1) return false;
        }
        vis[idx]=2;
        st.push(idx);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
        }
        vector<int>ans;
        vector<int>vis(numCourses,0);
        stack<int>st;
        bool k=true;
        for(int i=0;i<numCourses;i++)
        {
              if(vis[i]==0)
              k=dfs(i,adj,vis,st);
              if(k==false) break;
        }        
        while(!st.empty())
        {
            int x=st.top();
            cout<<x<<" ";
            ans.push_back(x);
            st.pop();
        }
        if(ans.size()==numCourses&&k==true)
        {
            reverse(ans.begin(),ans.end());
            return ans;
        }
        else 
        return {};
    }
};