class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        int l = -1;
        int r = m - 1;
        int ans = -1;
        while ( l <= r ) {
            int mid = ( l + r ) >> 1;
            vector<int> sum(n+1,0);
            for ( int i = 0 ; i <= mid ; ++i ) {
                auto q = queries[i];
                sum[q[0]] += q[2];
                sum[q[1] + 1] -= q[2]; 
            }
            for ( int i = 1 ; i < n ; ++i ) {
                sum[i] += sum[i-1];
                
            }
            bool check = true;
            for ( int i = 0 ; i < n && check ; ++i ) {
                if ( nums[i] > sum[i] ) {
                    check = false;
                }
            }
            if ( check ) {
                ans = mid + 1;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
