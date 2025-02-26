class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = 0;
        int localMin = 0;
        int localMax = 0;
        int sum = 0;
        for ( auto i : nums ) {
            sum += i;
            int val = max(abs(sum-localMax),abs(sum-localMin));
            ans = max(ans,val);
            localMax = max(localMax,sum);
            localMin = min(localMin,sum);
        }
        return ans;
    }
};
