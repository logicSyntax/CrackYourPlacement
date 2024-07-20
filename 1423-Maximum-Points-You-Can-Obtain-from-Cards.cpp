class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int i = 0;
        int j = 0;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int currSum = 0;

        for(; j<n-k; j++) {
            currSum += nums[j];
        }

        ans = max(ans, totalSum-currSum);

        while(j<n) {
            currSum -= nums[i++];
            currSum += nums[j++];

            ans = max(ans, totalSum - currSum);
        }

        return ans;
    }
};