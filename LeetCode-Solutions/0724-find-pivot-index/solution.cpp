class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for ( auto num : nums ) {
            sum += num;
        }
        int res = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( sum - res - nums[i] == res ) {
                return i;
            }
            res += nums[i];
        }
        return -1;
    }
};
