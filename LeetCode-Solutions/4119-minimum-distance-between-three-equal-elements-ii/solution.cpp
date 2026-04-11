class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,int> mp,mark,prev;
        int n = nums.size();
        int ans = 1e9;
        for ( int i = 0 ; i < n ; ++i ) {
            
            mp[nums[i]]++;
            if ( mp[nums[i]] >= 3 ) {
                ans = min(ans, i + 1 - mark[nums[i]]);
            }
            if ( mp[nums[i]] >= 2 ) {
                mark[nums[i]] = prev[nums[i]];
            }
            prev[nums[i]] = i + 1;
        }
        if ( ans == 1e9 ) ans = -1;
        else ans = ans * 2;
        return ans;
    }
};
