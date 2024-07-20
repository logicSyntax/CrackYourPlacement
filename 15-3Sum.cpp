class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i=0; i<n; i++) {
            if(i>0 && nums[i-1] == nums[i])
                continue;
            
            int low = i+1;
            int high = n-1;

            while(low < high) {
                int sum = nums[i] + nums[low] + nums[high];

                if(sum > 0)
                    high--;
                else if(sum < 0)
                    low++;
                else {
                    ans.push_back({nums[i], nums[low], nums[high]});
                    while(low<high && nums[low] == nums[low+1])
                        low++;
                    
                    while(high>low && nums[high] == nums[high-1])
                        high--;
                    
                    low++;
                    high--;
                }
            }
        }
        return ans;
    }
};