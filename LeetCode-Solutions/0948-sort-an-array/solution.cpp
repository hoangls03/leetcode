class Solution {
public:
    void merge_sort( vector<int>& nums ) {
        int n = nums.size();
        if ( n <= 1 ) return ;
        vector<int> nums1,nums2;
        for ( int i = 0 ; i < n/2 ; ++i ) {
            nums1.push_back(nums[i]);
        }
        for ( int i = n/2 ; i < n ; ++i ) {
            nums2.push_back(nums[i]);
        }
        merge_sort(nums1);
        merge_sort(nums2);
        int m = nums1.size();
        nums.clear();
        int pos = 0;
        int m2 = nums2.size();
        for ( int i = 0 ; i < nums1.size() ; ++i ) {
            while ( pos < m2 && nums2[pos] <= nums1[i] ) {
                nums.push_back(nums2[pos]);
                pos++;
            } 
            nums.push_back(nums1[i]);
        }
        for ( int i = pos ; i < nums2.size() ; ++i ) {
            nums.push_back(nums2[i]);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums);
        return nums;
    }
};
