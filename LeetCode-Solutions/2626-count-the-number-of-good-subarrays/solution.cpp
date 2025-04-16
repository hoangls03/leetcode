class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
        int left = 0;
        long long ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            k -= mp[nums[i]];
            mp[nums[i]]++;
            while ( k <= 0 ) {
                mp[nums[left]]--;
                k += mp[nums[left]];
                left++;
            }
            ans += left;
        }
        return ans;
    }
};
