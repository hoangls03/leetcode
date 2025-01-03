class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        for ( auto i : nums ) {
            sum += i;
        }
        int n = nums.size();
        long long tempSum = 0;
        int ans = 0;
        for ( int i = 0 ; i < n - 1 ; ++i ) {
            tempSum += nums[i];
            ans += ( tempSum >= sum - tempSum );
        }
        return ans;
    }
};
