class Solution {
private:
    int solve(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(row < 0 || col < 0)
            return INT_MAX;

        if(row == 0 && col == 0)
            return grid[row][col];
        
        if(dp[row][col] != -1)
            return dp[row][col];

        int up = solve(row-1, col, grid, dp);
        int left = solve(row, col-1, grid, dp);

        int sum = grid[row][col] + min(up, left);

        return dp[row][col] = sum;
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, grid, dp);
    }
};