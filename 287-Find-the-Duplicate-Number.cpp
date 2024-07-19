class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 1;
        int high = n-1;

        while(low <= high) {
            int mid = low + (high - low)/2;

            int count = 0;
            for(auto x : nums) {
                if(x <= mid)
                    count++;
            }

            if(count <= mid) {
                low = mid + 1;
            } else {
                high = mid -1;
            }
        }
        
        return low;
    }
};