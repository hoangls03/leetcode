class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mark(1005,0);
        int n = nums1.size();
        int m = nums2.size();
        for ( int i = 0 ; i < n ; ++i ) {
            mark[nums1[i]]++;
        }
        vector<int> ans;
        for ( auto i : nums2 ) {
            if ( mark[i] > 0 ) {
                ans.push_back(i);
                mark[i]--;
            }
        }
        return ans;
    }
};
