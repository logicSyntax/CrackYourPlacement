class Solution {
private:
    int solve(int index, vector<int> &dp) {
        if(index == 0)
            return 1;
        
        if(dp[index] != -1)
            return dp[index];

        int first = solve(index-1, dp);
        int second = 0;
        if(index-2 >= 0)
            second = solve(index-2, dp);
        
        return dp[index] = first + second;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};