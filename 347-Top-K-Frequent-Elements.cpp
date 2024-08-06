class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++) {
            map[nums[i]]++;
        }

        priority_queue<pair<int, int>> pq;
        for(auto pair : map) {
            pq.push({pair.second, pair.first});
        }

        vector<int> result;
        while(k) {
            result.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return result;
    }
};