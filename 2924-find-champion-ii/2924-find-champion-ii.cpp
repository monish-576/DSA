class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0);
        for(int i=0;i<edges.size();i++)
        {
            indegree[edges[i][1]]++;
        }
        int ans=-1,c=0;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0) 
            {
                c++;
                if(c>1) break;
                ans=i;
            }
        }
        return c>1?-1:ans;
    }
};