class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0, pos = 0;
        sort(nums.begin(),nums.end());
        for ( int i = 0 ; i < n ; ++i ) {
            while ( pos < n && nums[pos] - nums[i] <= 2*k ) {
                pos++;
            }
            ans = max(pos - i,ans);
        }
        return ans;
    }
};
