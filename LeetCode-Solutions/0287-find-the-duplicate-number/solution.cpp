class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 1;
        int r = n - 1;
        while ( l < r ) {
            int mid = l + r >> 1;
            int count_left = 0;
            for ( auto i : nums ) {
                if ( i <= mid ) count_left++;
            }
            if ( count_left > mid ) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
