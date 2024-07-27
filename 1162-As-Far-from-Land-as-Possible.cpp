class Solution {
private:
    bool isValid(int row, int col, vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        return row>=0 && row<n && col>=0 && col<m && grid[row][col] == 0;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        queue<pair<int, pair<int,int>>> q;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({0, {i, j}});
                }
            }
        }

        if(q.size() == m*n)
            return -1;

        while(!q.empty()) {
            int step = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            for(int i=0; i<4; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if(isValid(nrow, ncol, grid) && dist[nrow][ncol] > step+1) {
                    dist[nrow][ncol] = step+1;
                    q.push({step+1, {nrow, ncol}});
                } 
            }
        }

        int ans = INT_MIN;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(dist[i][j] != 1e9)
                    ans = max(ans, dist[i][j]);
            }
        }

        return ans == INT_MIN ? -1 : ans;
    }
};