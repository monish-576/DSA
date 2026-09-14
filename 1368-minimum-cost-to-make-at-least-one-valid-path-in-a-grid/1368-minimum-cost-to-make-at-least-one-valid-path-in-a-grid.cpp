class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        priority_queue<pair<int, pair<int,int>>,
                       vector<pair<int, pair<int,int>>>,
                       greater<pair<int, pair<int,int>>>> pq;

        pq.push({0, {0, 0}});

        while (!pq.empty())
        {
            int cost = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if (vis[r][c])
                continue;

            vis[r][c] = 1;

            if (r == m - 1 && c == n - 1)
                return cost;

            int dr[] = {0, 0, 1, -1};
            int dc[] = {1, -1, 0, 0};

            for (int i = 0; i < 4; i++)
            {
                int rx = r + dr[i];
                int cx = c + dc[i];

                if (rx >= 0 && rx < m && cx >= 0 && cx < n &&
                    vis[rx][cx] == 0)
                {
                    int newCost = cost;

                    if (grid[r][c] != i + 1)
                        newCost++;

                    pq.push({newCost, {rx, cx}});
                }
            }
        }

        return 0;
    }
};