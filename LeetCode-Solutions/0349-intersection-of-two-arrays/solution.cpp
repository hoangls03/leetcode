class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int j = 0;
        vector<int> ans;
        for ( int i = 0 ; i < n ; ++i ) {
            while ( j < m && nums1[i] > nums2[j] ) {
                j++;
            }
            if ( j < m && nums1[i] == nums2[j] ) {
                ans.push_back(nums1[i]);
                
            } 
            while ( j < m && nums1[i] == nums2[j] ) {
                j++;
            }
        }
        return ans;
    }
};
