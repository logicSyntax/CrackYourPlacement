class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> dp(n+1, 1);
        long long two = 1, three = 1, five = 1;

        for(int i=2; i<=n; i++) {
            long long twoMultiple = 2*dp[two];
            long long threeMultiple = 3*dp[three];
            long long fiveMultiple = 5*dp[five];

            long long mini = min(twoMultiple, min(threeMultiple, fiveMultiple));

            dp[i] = mini;

            if(mini == twoMultiple)
                two++;
            if(mini == threeMultiple)
                three++;
            if(mini == fiveMultiple)
                five++;
        }

        return (int)dp[n];
    }
};