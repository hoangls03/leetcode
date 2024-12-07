class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = 1e9;
        int sum = 0;
        int ans = 0;
        while ( l <= r ) {
            int mid = ( l + r ) >> 1;
            sum = 0;
            for ( int i : nums ) {
                sum += i/mid;
                if ( i % mid == 0 && i >= mid ) {
                    sum--;
                }
            }
            if ( sum <= maxOperations ) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        } 
        return ans;
    }
};
