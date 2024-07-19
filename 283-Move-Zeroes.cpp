class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        while(i< nums.size() && nums[i] != 0) {
            i++;
        }

        int j = i;
        while(j<nums.size() && nums[j] == 0) {
            j++;
        }

        while(i<j && j<nums.size()) {
            if(nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
    }
};