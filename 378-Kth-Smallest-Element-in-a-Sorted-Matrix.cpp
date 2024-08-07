class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        struct Compare {
            bool operator()(pair<int, pair<int,int>> &a, pair<int, pair<int,int>> &b) {
                return a.first > b.first;
            }
        };

        priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, Compare> pq;
        int n = matrix.size();

        for(int i=0; i<n; i++) {
            pq.push({matrix[i][0], {i, 0}});
        }

        int result = 0;
        for(int i=0; i<k; i++) {
            auto p = pq.top();
            pq.pop();

            result = p.first;
            int row = p.second.first;
            int col = p.second.second;

            if(col + 1 < n) {
                pq.push({matrix[row][col+1], {row, col+1}});
            }
        }

        return result;
    }
};