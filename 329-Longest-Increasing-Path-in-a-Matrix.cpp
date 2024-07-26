class Solution {
private:
    bool isValid(int row, int col, vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        return row>=0 && row<n && col>=0 && col<m;
    }
    int solve(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(dp[row][col] != -1)
            return dp[row][col];
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        int ans = 1;
        for(int i=0; i<4; i++) {
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if(isValid(nrow, ncol, grid) && grid[row][col] > grid[nrow][ncol]) {
                ans = max(ans, 1 + solve(nrow, ncol, grid, dp));
            }
        }

        return dp[row][col] = ans;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(dp[i][j] == -1)
                    ans = max(ans, solve(i, j, matrix, dp));
            }
        }

        return ans;
    }
};