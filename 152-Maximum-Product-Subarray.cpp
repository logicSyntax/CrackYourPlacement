class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double maxi = INT_MIN;
        double product = 1;

        for(int i=0; i<nums.size(); i++) {
            product *= nums[i];
            maxi = max(product, maxi);
            if(product == 0)
                product = 1;
        }

        product = 1;
        for(int i=nums.size()-1; i>=0; i--) {
            product *= nums[i];

            maxi = max(product, maxi);
            if(product == 0)
                product = 1;
        }

        return (int)maxi;
    }
};