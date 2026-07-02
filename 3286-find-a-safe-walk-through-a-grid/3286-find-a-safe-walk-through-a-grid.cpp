class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> best(m, vector<int>(n, -1));
        queue<pair<pair<int,int>,int>> q;

        int startHealth = health - grid[0][0];
        if(startHealth < 1)
            return false;

        q.push({{0,0}, startHealth});
        best[0][0] = startHealth;

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while(!q.empty()) {
            auto cur = q.front();
            q.pop();

            int r = cur.first.first;
            int c = cur.first.second;
            int h = cur.second;

            if(r == m-1 && c == n-1)
                return true;

            for(int i=0;i<4;i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n) {
                    int nh = h - grid[nr][nc];

                    if(nh >= 1 && nh > best[nr][nc]) {
                        best[nr][nc] = nh;
                        q.push({{nr,nc}, nh});
                    }
                }
            }
        }

        return false;
    }
};