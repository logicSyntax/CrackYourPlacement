class Solution {
private:
    void solve(int index, vector<int> &nums, vector<vector<int>> &result, vector<int> &ans, int k) {
        if(ans.size() == k) {
            result.push_back(ans);
            return;
        }

        if(index == nums.size())
            return;
        
        ans.push_back(nums[index]);
        solve(index+1, nums, result, ans, k);

        ans.pop_back();
        solve(index+1, nums, result, ans, k);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for(int i=0; i<n; i++) {
            nums.push_back(i+1);
        }

        vector<vector<int>> result;
        vector<int> ans;
        
        solve(0, nums, result, ans, k);

        return result;
    }
};