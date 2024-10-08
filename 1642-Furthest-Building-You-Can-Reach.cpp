class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int n = heights.size();

        int i=1;
        for( ; i<n; i++) {
            int diff = heights[i] - heights[i-1];

            if(diff <= 0)
                continue;
            
            bricks -= diff;
            pq.push(diff);

            if(bricks < 0) {
                bricks += pq.top();
                pq.pop();
                ladders--;
            }

            if(ladders < 0)
                break;
        }

        return i-1;
    }
};