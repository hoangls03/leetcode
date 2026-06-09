class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int minNum = 0, maxNum = 0;
        maxNum = nums[0];
        minNum = nums[0];
        int maxVal = 0;
        for ( int i = 1 ; i < n ; ++i ) {
            maxNum = max(maxNum,nums[i]);
            minNum = min(minNum,nums[i]);
            maxVal = max(maxVal,maxNum - minNum);
        }
        long long ans = 1LL * maxVal * k;
        return ans;
    }
};
