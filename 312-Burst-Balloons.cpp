class Solution {
private:
    int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
        if(i>j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        int maxi = INT_MIN;
        for(int index=i; index<=j; index++) {
            int coins = nums[i-1]*nums[index]*nums[j+1] + solve(i, index-1, nums, dp) + solve(index+1, j, nums, dp);
            maxi = max(coins, maxi);
        }

        return dp[i][j] = maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(1, n, nums, dp);
    }
};