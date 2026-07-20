class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>res(m,vector<int>(n,0));
        int p=k%(m*n),l=0;
        if(p==0) return grid;
        while(l<p)
        {
            int dumy=grid[m-1][n-1];
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                        if(i==0&&j==0)
                        continue;
                        else if(j==0&&i>=1)
                        res[i][j]=grid[i-1][n-1];
                        else
                        res[i][j]=grid[i][j-1];
                }
            }
            res[0][0]=dumy;
            grid=res;
            l++;
        }
        return res;
    }
};