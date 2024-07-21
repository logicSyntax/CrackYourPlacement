class Solution {
private:
    void merge(vector<int> &nums, int low, int mid, int high, int &count) {
        int n1= mid-low+1;
        int n2= high-mid;

        vector<int> left(n1);
        vector<int> right(n2);

        for(int i=0; i<n1; i++) {
            left[i] = nums[i+low];
        }

        for(int i=0; i<n2; i++) {
            right[i] = nums[i+mid+1];
        }

        int i = 0;
        int j = 0;
        int k = low;

        while(i<n1 && j<n2) {
            if(left[i] < right[j]) {
                nums[k++] = left[i++];
            } else {
                nums[k++] = right[j++];
            }
        }

        while(i<n1) {
            nums[k++] = left[i++];
        } 
        while(j<n2) {
            nums[k++] = right[j++];
        }
    }

    int countPair(vector<int> &nums, int low, int mid, int high) {
        int count = 0;
        int j = mid+1;
        for(int i=low; i<=mid; i++) {
            while(j<= high && nums[i] > 2*(long long)nums[j]) 
                j++;
            count += j-(mid+1);
        }

        return count;
    }
    int mergeSort(vector<int> &nums, int low, int high) {
        int count = 0;
        if(low < high) {
            int mid = low + (high - low)/2;

            count += mergeSort(nums, low, mid);
            count += mergeSort(nums, mid+1, high);
            count += countPair(nums, low, mid, high);
            merge(nums, low, mid, high, count);
        }

        return count;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};