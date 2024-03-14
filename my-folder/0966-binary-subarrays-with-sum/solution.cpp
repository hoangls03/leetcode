class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        map<int,int> mp;
        mp.clear();
        int sum = 0,ans = 0;
        mp[0] = 1;
        for ( int i = 0 ; i < n ; ++i ) {
            sum += nums[i];
            ans += mp[sum - goal];
            mp[sum]++;
        }
        return ans;
    }
};
