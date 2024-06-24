class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> flips(n,0);
        int ans = 0;
        bool flip = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( i >= k ) {
                flip ^= flips[i-k];
            } 
            if ( flip == nums[i] ) {
                if ( i + k > n ) return -1;
                flips[i] = 1;
                flip ^= 1;
                ans++;
            }
        }
        return ans;
    }
};
