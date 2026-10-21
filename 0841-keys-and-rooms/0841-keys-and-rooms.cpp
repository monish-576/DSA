class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<vector<int>>&rooms)
    {
        vis[node]=1;
        for(int i=0;i<rooms[node].size();i++)
        {
            if(vis[rooms[node][i]]==0)
            {
                dfs(rooms[node][i],vis,rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int>vis(rooms.size(),0);
        vis[0]=1;
        for(int i=0;i<rooms[0].size();i++)
        {
            dfs(rooms[0][i],vis,rooms);
        }
        bool flag=true;
        for(int i=0;i<vis.size();i++)
        {
            if(vis[i]==0)
            {
                flag=false;
                break;
            }
        }
        return flag;
    }
};