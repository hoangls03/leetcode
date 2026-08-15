class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, ans = 0;
        sort(nums.begin(),nums.end());
        for ( int i = 0 ; i < n ; ++i ) {
            sum ^= nums[i];
            if ( sum != 0 ) {
                ans = i + 1;
            }
        }

        sum = 0;
        for ( int i = n - 1 ; i >= 0 ; --i ) {
            sum ^= nums[i];
            if ( sum != 0 ) {
                ans = max(ans,n - i);
            }
        }
        return ans;
    }
};
