class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 1e6 + 1));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            q;
        q.push({0, {0, 0}});
        vis[0][0]=0;
        int dr[] = {-1, 0, 0, 1};
        int dc[] = {0, -1, 1, 0};
        while (!q.empty()) {
            int dist = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            q.pop();
            if (r == m - 1 && c == n - 1)
                return dist;
            for (int i = 0; i < 4; i++) {
                int rx = r + dr[i];
                int cx = c + dc[i];
                if (rx >= 0 && rx < m && cx >= 0 && cx < n) {
                    int effort =
                        max(dist, abs(heights[r][c] - heights[rx][cx]));
                    if (effort < vis[rx][cx]) {

                        vis[rx][cx] = effort;

                        q.push({effort, {rx, cx}});
                    }
                }
            }
        }
        return -1;
    }
    };