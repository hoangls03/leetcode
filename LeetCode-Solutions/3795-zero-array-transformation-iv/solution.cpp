class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> edge(n);
        for ( int i = 0 ; i < n ; ++i ) {
            for ( auto q : queries ) {
                if ( q[0] <= i && i <= q[1] ) {
                    edge[i].push_back(q[2]);
                } else {
                    edge[i].push_back(0);
                }
            }
        }
        int q = queries.size();
        vector<int> res(n,1e9);
        for ( int i = 0 ; i < n ; ++i ) {
            vector<int> dp(1005,0);
            dp[0] = 1;
            if ( nums[i] == 0 ) {
                res[i] = -1;
                continue;
            }
            for ( int j = 0 ; j < q ; ++j ) {
                for ( int k = nums[i] ; k >= edge[i][j] ; --k ) {
                    dp[k] |= dp[k-edge[i][j]];
                }
                if ( dp[nums[i]] != 0 ) {
                    res[i] = j;
                    break;
                }
            }

        }
        int ans = -1e9;
        for ( auto i : res ) {
            ans = max(ans,i);
        }
        return ans == 1e9 ? -1 : ans + 1;
    }
};
