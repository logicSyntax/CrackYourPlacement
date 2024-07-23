class Solution {
private:
    bool isValid(int row, int col, vector<vector<int>> &img, int oldColor) {
        int n = img.size();
        int m = img[0].size();

        if(row>=0 && row<n && col>=0 && col<m && img[row][col] == oldColor)
            return true;
        
        return false;
    }
    void solve(int row, int col, vector<vector<int>> &img, int oldColor, int color) {
        queue<pair<int, int>> q;
        img[row][col] = color;
        q.push({row, col});

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while(!q.empty()) {
            auto frontNode = q.front();
            q.pop();

            for(int i=0; i<4; i++) {
                int nrow = frontNode.first + dr[i];
                int ncol = frontNode.second + dc[i];

                if(isValid(nrow, ncol, img, oldColor)) {
                    img[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int oldColor = image[sr][sc];

        if(oldColor == color)
            return image;

        solve(sr, sc, image, oldColor, color);

        return image;
    }
};