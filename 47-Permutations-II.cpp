class Solution {
    //Time Complexity === O(N! * N)
    //Space Complexity === O(2*N) auxillary + rec. stack
private:
    void solve(int index, vector<int> &nums, vector<vector<int>> &result) {
        if(index == nums.size()) {
            result.push_back(nums);
            return;
        }
        unordered_set<int> st;
        for(int i=index; i<nums.size(); i++) {
            if(st.find(nums[i]) != st.end())
                continue;
            
            st.insert(nums[i]);
            swap(nums[index], nums[i]);
            solve(index+1, nums, result);
            swap(nums[index], nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        solve(0, nums, result);

        return result;
    }
};