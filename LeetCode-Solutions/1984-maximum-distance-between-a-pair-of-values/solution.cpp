class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int pos = n - 1;
        int ans = 0;
        for ( int i = m - 1 ; i >= 0 ; --i ) {
            while ( pos >= 0 && nums1[pos] <= nums2[i] ) {
                if ( pos <= i ) {
                    ans = max(ans, i - pos);
                }
                pos--;
            }
            if ( pos <= i && pos >= 0 && nums1[pos] <= nums2[i]) {
                    ans = max(ans, i - pos);
            }
        }
        return ans;
    }
};
