class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int ans = -1;
        int n = nums1.size(), j = 0;
        int m = nums2.size();
        for ( int i = 0 ; i < n ; ++i ) {
            while ( j < m && nums1[i] > nums2[j] ) {
                j++;
            }
            if ( j < m && nums1[i] == nums2[j] ) {
                ans = nums1[i];
                break;
            }
        }
        return ans;
    }
};
