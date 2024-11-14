class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1;
        int r = 1e5;
        int ans = 1e5;
        while ( l <= r ) {
            int mid = ( l + r ) >> 1;
            int nums = 0;
            for ( auto i : quantities ) {
                nums += i / mid;
                if ( i % mid != 0 ) nums++;
            } 
            if ( nums > n ) {
                l = mid + 1;
            } else {
                r = mid - 1;
                ans = min(ans,mid);
            }
        }
        return ans;
    }
};
