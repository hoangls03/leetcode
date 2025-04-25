class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        map<int,long long> mp;
        long long sum = 0,ans = 0;
        mp[0] = 1;
        for ( int i = 0 ; i < n ; ++i ) {
            sum = ( sum + (nums[i] % modulo == k) )%modulo;
            int tmp = (sum - k)%modulo;
            tmp = (tmp + modulo)%modulo;
            ans += mp[tmp];
            mp[sum%modulo]++;
        }
        return ans;
    }
};
