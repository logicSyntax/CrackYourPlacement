class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 1;
        int number = nums[0];

        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == number) {
                freq++;
            } else {
                freq--;
            }

            if(freq == 0) {
                freq = 1;
                number = nums[i];
            }
        }

        return number;

    }
};