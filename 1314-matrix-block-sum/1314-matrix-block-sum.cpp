class Solution {
public:
    int m, n, kk;
    int sum(vector<vector<int>>& mat, int i, int j) {
        int s = 0;
        for (int r = i - kk; r <= i + kk; r++) {
            for (int c = j - kk; c <= j + kk; c++) {
                if (r >= 0 && c >= 0 && r < m && c < n) {
                    s += mat[r][c];
                }
            }
        }
        return s;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        m = mat.size(), n = mat[0].size(), kk = k;
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = sum(mat, i, j);
            }
        }
        return ans;
    }
};
