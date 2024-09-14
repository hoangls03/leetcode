class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int max_num = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            max_num = max(max_num,nums[i]);
        }
        int res = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( nums[i] == max_num ) {
                res++;
                ans = max(ans,res);
            } else {
                res = 0;
            }
        }
        return ans;
    }
};
