class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long n = nums.size();
        long long pos = 0;
        long long ans = 0;
        for ( long long i = 1 ; i < n ; ++i ) {
            if ( nums[i] > nums[pos] || i == n - 1 ) {
                ans += nums[pos] * ( i - pos );
                pos = i;
            }
        }
        return ans;
    }
};
