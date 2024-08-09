class Solution {
private:
    void solve(int index, vector<int> &nums, vector<vector<int>> &result, vector<int> &ans, int target) {
        if(target == 0) {
            result.push_back(ans);
            return;
        }

        for(int i=index; i<nums.size(); i++) {
            if(i > index && nums[i] == nums[i-1])
                continue;
            
            if(nums[i] > target) {
                break;
            }
            ans.push_back(nums[i]);
            solve(i+1, nums, result, ans, target-nums[i]);

            ans.pop_back();
        }
        
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> result;
        vector<int> ans;

        solve(0, candidates, result, ans, target);

        return result;
    }
};