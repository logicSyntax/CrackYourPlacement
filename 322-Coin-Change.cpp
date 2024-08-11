class Solution {
private:
    int solve(int index, vector<int> &coins, int amount, vector<vector<int>> &dp) {
        if(index == 0) {
            if(amount%coins[index] == 0) {
                return amount/coins[index];
            }

            return 1e9;
        }
        
        if(dp[index][amount] != -1)
            return dp[index][amount];

        int pick = 1e9;
        if(amount >= coins[index]) {
            pick = 1 + solve(index, coins, amount - coins[index], dp);
        }

        int notPick = solve(index-1, coins, amount, dp);

        return dp[index][amount] = min(pick, notPick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = solve(n-1, coins, amount, dp);

        return ans == 1e9 ? -1 : ans;
    }
};