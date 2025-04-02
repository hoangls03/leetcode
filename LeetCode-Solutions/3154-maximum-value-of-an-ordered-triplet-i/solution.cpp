class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 0 ; j < i ; ++j ) {
                for ( int z = 0 ; z < j ; ++z ) {
                    ans = max(ans,1LL*(nums[z]-nums[j])*nums[i]);
                }
            }
        }
        return ans;
    }
};
