class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long target = 1;
        int pos = 0;
        int sz = nums.size();
        int ans = 0;
        while ( target <= n ) {
            if ( pos < sz && nums[pos] <= target ) {
                target += nums[pos];
                pos++;
            } else {
                target += target;
                ans++;
            }
        }
        return ans;
    }
};
