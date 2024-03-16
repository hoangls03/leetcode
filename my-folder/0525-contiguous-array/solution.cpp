class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0,sum = 0;
        map<int,int> mp;
        mp.clear();
        mp[0] = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( nums[i] == 0 ) {
                sum += -1;
            }
            else sum += nums[i];
            if ( sum == 0 || mp[sum] != 0 ) {
                ans = max(ans,i + 1- mp[sum]);
            }
            else mp[sum] = i + 1;
        }
        return ans;
    }
};
