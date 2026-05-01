class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int preFix = 0;
        int sufFix = 0;
        int sufSum = 0;
        for ( int i = n - 1 ; i >= 0 ; --i ) {
            sufSum += nums[i];
            sufFix += sufSum;
        }
        int curSum = 0;
        int ans = -2e9;
        for ( int i = 0 ; i < n ; ++i ) {
            sufFix -= sufSum;
            sufSum -= nums[i];
            ans = max(ans,sufFix + preFix);
            preFix += nums[i] * ( n - 1 ) - curSum;
            curSum += nums[i];
        }
        return ans;
    }
};
