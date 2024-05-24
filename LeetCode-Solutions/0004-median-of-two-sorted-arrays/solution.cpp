class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> vt;
        for ( auto i : nums1 ) {
            vt.push_back(i);
        }
        for ( auto i : nums2 ) {
            vt.push_back(i);
        }
        sort(vt.begin(),vt.end());
        double ans;
        if ( vt.size() & 1 ) {
            ans = vt[vt.size()/2];
        }
        else {
            ans = vt[vt.size()/2 ];
            ans = (ans + vt[vt.size()/2-1])/2;
        }
        return ans;
    }
};
