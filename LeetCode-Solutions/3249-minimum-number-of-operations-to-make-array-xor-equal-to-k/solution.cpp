class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xor_result = nums[0];
        for ( int i = 1 ; i < nums.size() ; ++i ) {
            xor_result ^= nums[i];
        }
        vector<int> mark(20,0);
        while ( k > 0 ) {
            int temp = log2(k);
            mark[temp]++;
            k = k - (1<<(temp));
        }
        while ( xor_result > 0 ) {
            int temp = log2(xor_result);
            mark[temp]++;
            xor_result = xor_result - (1<<(temp));
        }
        int ans = 0;
        for ( int i = 0 ; i < 20 ; ++i ) {
            if ( mark[i] & 1 ) {
                ans++;
            }
        }
        return ans;
    }
};
