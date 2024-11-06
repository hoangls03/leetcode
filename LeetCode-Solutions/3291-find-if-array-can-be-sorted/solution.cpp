class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int maxNum = 0;
        int minNum = 1e9;
        int prev = __builtin_popcount(nums[0]);
        int localMax = 0;
        for ( auto i : nums ) {
            int bit = __builtin_popcount(i);
            if ( bit == prev ) {
                minNum = min(minNum,i);
                localMax = max(localMax,i);
            } else {
                minNum = i;
                maxNum = localMax;
                localMax = i;
            }
            prev = bit;
            if ( maxNum > minNum ) {
                return false;
            }
        }
        return true;
    }
};
