class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        while ( k > 0 ) {
            int pos = n - 1;
            for ( int i = n - 1 ; i >= 0 ; --i ) {
                if ( nums[i] <= nums[pos] ) {
                    pos = i;
                }
            }
            nums[pos] = nums[pos]*multiplier;
            k--;
        }
        return nums;
    }
};
