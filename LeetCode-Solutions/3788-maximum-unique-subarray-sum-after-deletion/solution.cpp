class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = nums[0];
        for ( int i = 1 ; i < n ; ++i ) {
            if ( nums[i] != nums[i-1] ) {
                ans = max(ans + nums[i],nums[i]);
            }
        }
        return ans;
    }
};
