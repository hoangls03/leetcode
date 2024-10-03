class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long sum_n = 0;
        for ( auto i : nums ) {
            sum_n += i;
        }
        sum_n %= p;
        if ( sum_n == 0 ) return 0;
        long long sum = 0;
        int ans = 1e9;
        map<long long,int> mp;
        mp[sum_n] = 1;
        for ( int i = 0 ; i < n ; ++i ) {
            sum += nums[i];
            sum %= p;
            if ( mp[sum] != 0 + (i == n - 1) ) {
                ans = min(ans,i-mp[sum]+2);
            }
            mp[(sum + sum_n)%p] = i + 2;
        }
        if ( ans == 1e9 ) ans = -1;
        return ans;
    }
};
