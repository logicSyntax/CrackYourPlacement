class Solution {
private:
    int solve(int low, int high, string s, vector<vector<int>> &dp) {
        if(low > high)
            return 0;
        
        if(low == high)
            return 1;
        
        if(dp[low][high] != -1)
            return dp[low][high];

        int i = low+1;
        while(i <= high && s[i] == s[low])
            i++;

        int ans1 = 1 + solve(i, high, s, dp);

        int ans2 = INT_MAX;
        for(int j=i; j<=high; j++) {
            if(s[j] == s[low]) {
                int count = solve(i, j-1, s, dp) + solve(j, high, s, dp);
                ans2 = min(ans2, count);
            }
        }

        return dp[low][high] = min(ans1, ans2);

    }
public:
    int strangePrinter(string s) {
        int n = s.size();
        int low = 0;
        int high = n-1;

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return solve(low, high, s, dp);
    }
};