class Solution {
private:
    bool isPallindrome(int start, int end, string s) {
        while(start <= end) {
            if(s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
    void solve(int index, string &s, vector<vector<string>> &result, vector<string> &ans) {
        if(index == s.size()) {
            result.push_back(ans);
            return;
        }
        
        for(int i=index; i<s.size(); i++) {
            if(isPallindrome(index, i, s)) {
                string str = s.substr(index, i-index+1);
                ans.push_back(str);
                solve(i+1, s, result, ans); 
                ans.pop_back(); 
            }
            
        }
        
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> ans;
        solve(0, s, result, ans);

        return result;
    }
};