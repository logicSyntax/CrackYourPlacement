class Solution {
private:
    bool isValid(int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &vis){
        int n = grid.size();
        int m = grid[0].size();

        if(row >=0 && row <n && col>=0 && col<m && grid[row][col]=='1' && !vis[row][col])
            return true;
        
        return false;
    }

    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    void solve(int row, int col, vector<vector<bool>> &vis, vector<vector<char>> &grid) {
        vis[row][col] = true;

        for(int i=0; i<4; i++) {
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if(isValid(nrow, ncol, grid, vis)) {
                solve(nrow, ncol, vis, grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    solve(i, j, vis, grid);
                    count++;
                }
            }
        }

        return count;
    }
};