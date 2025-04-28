class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans = 0;
        long long r = 0;
        long long sum = 0;
        for ( long long i = 0 ; i < n ; ++i ) {
            r = max(r,i);
            int len = 0;
            while ( r < n && (sum+nums[r])*(r-i+1) < k ) {
                sum += nums[r];
                len = r - i + 1;
                r++;
            }
            //cout<<i<<" "<<r<<" "<<sum<<" "<<sum*(r-i)<<" "<<r-i<<" "<<nums[i]<<" "<<len<<'\n';
            ans += r - i;
            if ( sum > 0 ) sum -= nums[i];
        }
        return ans;
    }
};
