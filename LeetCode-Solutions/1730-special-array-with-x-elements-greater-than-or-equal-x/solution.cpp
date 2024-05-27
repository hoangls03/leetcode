class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        int l = 1;
        int r = 1000;
        int ans = -1;
        while ( l <= r ) {
            int count = 0;
            int mid = ( l + r ) >> 1;
            for ( int i = 0 ; i < n ; ++i ) {
                if( nums[i] >= mid ) {
                    count++;
                }
            }
            if ( count == mid ) {
                ans = mid;
                break;
            } 
            if ( count < mid ) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
