#define ii pair<int,int>
#define fi first
#define se second
class Solution {
public:
    map<vector<int>,ii> mp;
    ii cal(vector<int>& nums) {
        int n = nums.size();
        if ( n == 1 ) {
            return {nums[0],0};
        }

        if ( mp.contains(nums) ) return mp[nums];
        vector<int> nums1 = {nums.begin() + 1,nums.begin() + n};
        vector<int> nums2 = {nums.begin(), nums.begin() + n - 1};
        ii val1 = cal(nums1);
        ii val2 = cal(nums2);

        val1.se += nums[0];
        val2.se += nums[n-1];
        int diff1 = val1.se - val1.fi;
        int diff2 = val2.se - val2.fi;
        
        if ( diff1 > diff2 ) {
            mp[nums] = {val1.se,val1.fi};
            return {val1.se,val1.fi};
        } else {
            mp[nums] = {val2.se,val2.fi};
            return {val2.se,val2.fi};
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        ii val = cal(nums);
        mp.clear();
        if ( val.fi >= val.se ) {
            return true;
        }
        return false;
    }
};
