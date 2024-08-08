class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for(int i=0; i<n-k; i++) {
            pq.push({nums[i], i});
        }

        vector<int> result;
        int index = -1;
        for(int i=n-k; i<n; i++) {
            pq.push({nums[i], i});

            while(pq.top()[1] < index) 
                pq.pop();
            
            result.push_back(pq.top()[0]);
            index = pq.top()[1];
            pq.pop();
        }

        return result;
    }
};