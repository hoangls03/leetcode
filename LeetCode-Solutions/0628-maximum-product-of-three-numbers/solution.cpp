class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int n = nums.size();
        int maxPositive = nums[n-1] * nums[n-2];
        int maxNegative = nums[0] * nums[1];
        ans = max(maxNegative * nums[n-1], maxPositive * nums[n-3]);
        return ans;
    }
};
