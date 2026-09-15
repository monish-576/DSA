class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        for(int d=1;d<grid.size();d++)
        {
            int i=0;
            int j=d;
            vector<int>ans;
            while(j<grid.size()&&i<grid.size())
            {
                ans.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(ans.begin(),ans.end());
            i=0;
            j=d;
            int k=0;
            while(j<grid.size()&&i<grid.size())
            {
                grid[i][j]=ans[k];
                k++;
                i++;
                j++;
            }
        }
        for(int d=0;d<grid.size();d++)
        {
            int i=d;
            int j=0;
            vector<int>ans;
            while(j<grid.size()&&i<grid.size())
            {
                ans.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(ans.begin(),ans.end(),greater<int>());
            i=d;
            j=0;
            int k=0;
            while(j<grid.size()&&i<grid.size())
            {
                grid[i][j]=ans[k];
                k++;
                i++;
                j++;
            }
        }
        vector<vector<int>>res;
        for(int i=0;i<grid.size();i++)
        {
            vector<int>ans;
            for(int j=0;j<grid.size();j++)
            {
                 ans.push_back(grid[i][j]);
            }
            res.push_back(ans);
        }
        return res;
    }
};