class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1, dcr = 1,ans = 1;
        int n = nums.size();
        for ( int i = 1 ; i < n ; ++i ) {
            if ( nums[i] > nums[i-1] ) {
                inc++;
                dcr = 1;
            } else if ( nums[i] < nums[i-1] ) {
                dcr++;
                inc = 1;
            } else {
                inc = 1;
                dcr = 1;
            }
            ans = max({ans,inc,dcr});
        }
        ans = max({ans,inc,dcr});
        return ans;
    }
};
