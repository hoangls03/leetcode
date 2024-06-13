class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> ans;
        for ( int i = 0 ; i < m ; ++i ) {
            int pos = -1;
            for ( int j = 0 ; j < n ; ++j ) {
                if ( nums2[j] == nums1[i] ) pos = j;
            }
            int temp = -1;
            for ( int j = pos ; j < n ; ++j ) {
                if ( nums2[j] > nums1[i] ) {
                    temp = nums2[j];
                    break;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
