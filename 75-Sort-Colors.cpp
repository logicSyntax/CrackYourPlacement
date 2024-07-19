class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = -1;
        int high = nums.size();

        int i=0; 
        while(i < high) {
            if(nums[i] == 0) {
                low++;
                swap(nums[low], nums[i]);
                i++;
            } else if(nums[i] == 1) {
                i++;
            } else {
                high--;
                swap(nums[high], nums[i]); 
            }
        }
    }
};