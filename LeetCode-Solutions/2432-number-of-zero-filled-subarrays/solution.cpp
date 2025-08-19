class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, count0 = 0;
        for ( auto i : nums ) {
            if ( i == 0 ) {
                count0++;
            } else {
                ans += count0*(count0 + 1)/2;
                count0 = 0;
            }
        }
        ans += count0*(count0 + 1)/2;
        return ans;
    }
};
