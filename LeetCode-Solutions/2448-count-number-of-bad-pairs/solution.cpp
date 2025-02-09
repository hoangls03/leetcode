class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        map<int,int> mp;
        long long n = nums.size();
        for ( int i = 0 ; i < n ; ++i ) {
            ans += mp[nums[i]-i];
            mp[nums[i]-i]++;
        }
        long long total = n*(n-1)/2;
        return total - ans;
    }
};
