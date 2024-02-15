class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<long long> sum(n,0);
        for ( int i = 0 ; i < n ; ++i ) {
            sum[i] = ( i == 0 ) ? nums[i] : (sum[i-1] + nums[i]);
        }
        long long ans = -1;
        for ( int i = 2 ; i < n ; ++i ) {
            if ( nums[i] < sum[i-1] ) {
                ans = max(ans,sum[i]);
            }
        }
        return ans;
    }
};
