class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int rem = 0;
        int count = 0;
        unordered_map<int, int> map;
        map[rem] = 1;

        for(int i=0; i<n; i++) {
            sum += nums[i];

            rem = sum%k;

            if(rem < 0)
                rem = (rem+k)%k;
            
            if(map.find(rem) != map.end()) {
                count += map[rem];
            }

            map[rem]++;
        }

        return count;
    }
};