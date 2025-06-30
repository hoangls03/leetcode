class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> mp;
        int ans = 0;
        for ( auto i : nums ) {
            mp[i]++;
            int val = max(mp[i-1],mp[i+1]);
            if ( val != 0 ) {
                ans = max(ans,val + mp[i]);
            }
        }
        return ans;
    }
};
