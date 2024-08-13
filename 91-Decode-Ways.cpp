class Solution {
private:
    int solve(int index, string s, vector<int> &dp) {
        if(index == s.size())
            return 1;
        
        if(dp[index] != -1)
            return dp[index];

        int count = 0;
        if(s[index] != '0') 
            count += solve(index+1, s, dp);
        
        if(index+1<s.size() && (s[index] == '1' || s[index]=='2' && s[index+1] <= '6'))
            count += solve(index+2, s, dp);
        
        return dp[index] = count;
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, -1);
        return solve(0, s, dp);
    }
};