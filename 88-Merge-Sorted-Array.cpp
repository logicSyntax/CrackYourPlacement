class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0)
            return;
        int k = nums1.size()-1;
        int end1 = m-1;
        int end2 = n-1;

        while(end1>=0 && end2>=0) {
            if(nums1[end1] < nums2[end2]) {
                nums1[k--] = nums2[end2--];
            } else{
                nums1[k--] = nums1[end1--];
            } 
        }

        while(end2 >= 0) {
            nums1[k--] = nums2[end2--];
        }
    }
};