class Solution {
private:
    void solve(int index, vector<int> &nums, vector<vector<int>> &result, vector<int> &ans) {
        result.push_back(ans);

        for(int i=index; i<nums.size(); i++) {
            if(i != index && nums[i] == nums[i-1])
                continue;
            
            ans.push_back(nums[i]);
            solve(i+1, nums, result, ans);
            ans.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> ans;
        solve(0, nums, result, ans);

        return result;
    }
};