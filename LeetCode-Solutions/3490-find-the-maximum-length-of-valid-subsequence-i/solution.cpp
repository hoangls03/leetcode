class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        for ( int  i = 0 ; i < n ; ++i ) {
            nums[i] %= 2;
        }
        int diff0 = 0;
        int diff1 = 0;
        int odd = 0;
        int even = 0;
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( nums[i] & 1 ) odd++;
            else even++;
            if ( diff0 & 1 ) {
                if ( nums[i] == 1 ) diff0++;
            } else {
                if ( nums[i] == 0 ) diff0++;
            }
            if ( (diff1 & 1) && nums[i] == 0 ) diff1++;
            if ( (diff1 % 2 == 0 ) && nums[i] == 1 ) diff1++;
        }
        ans = max({ans,odd,even,diff0,diff1});
        return ans;
    }
};
