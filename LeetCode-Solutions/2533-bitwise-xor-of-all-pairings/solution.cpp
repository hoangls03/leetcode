class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int ans = 0;
        if ( m & 1 ) {
            for ( auto i : nums2 ) {
                ans ^= i;
            }
        }
        if ( n & 1 ) {
            for ( auto i : nums1 ) {
                ans ^= i;
            }
        }
        return ans;
    }
};
