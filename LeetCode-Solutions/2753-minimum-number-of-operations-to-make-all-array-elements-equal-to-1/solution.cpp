class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        int m = __gcd(nums[0],nums[1]);
        for ( int i = 0 ; i < n; ++i ) {
            m = __gcd(m,nums[i]);
        }
        if ( m != 1 ) return -1;
        for ( auto i : nums ) {
            count += (i != 1);
        }
        int ans = 1e9;
        if ( count != n ) return count;
        for ( int i = 0 ; i < n ; ++i ) {
            m = nums[i];
            for ( int j = i + 1 ; j < n ; ++j ) {
                m = __gcd(m,nums[j]);
                if ( m == 1 ) {
                    ans = min(ans,j - i + n - 1);
                }
            }
        }
        return ans;
    }
};
