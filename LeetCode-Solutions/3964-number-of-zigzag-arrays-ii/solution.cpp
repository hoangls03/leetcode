const int oo = 1e9 + 7;
class Solution {
public:
    /*
        1: greater than
        0: less than
    */
    vector<vector<int>> matMul( vector<vector<int>> a, vector<vector<int>> b) {
        int m = a.size();
        int k = b[0].size();
        int n = b.size();
        vector<vector<int>> c(m,vector<int>(k,0));
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int z = 0 ; z < k ; ++z ) {
                for ( int j = 0 ; j < n ; ++j ) {
                    c[i][z] = (c[i][z] + 1LL * a[i][j] * b[j][z])%oo; 
                }
            }
        }
        return c;
    }

    vector<vector<int>> matPow( vector<vector<int>>& a, long long m ) {
        if ( m == 0 ) {
            int n = a.size();
            vector<vector<int>> b(n , vector<int>(n,0));
            
            for ( int i = 0 ; i < n ; ++i ) {
                for ( int j = 0 ; j < n ; ++j ) {
                    b[i][j] = (i == j);
                }
            }
            return b;
        }
        if ( m & 1 ) {
            return matMul(matPow(a,m - 1),a);
        }
        auto p = matPow(a,m/2);
        return matMul(p,p);
    }
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        vector<vector<int>> ans(m, vector<int>(m,0));
        for ( int i = 0 ; i < m ; ++i ) {
            int count1 = m - 1 - i;
            for ( int j = 0 ; j < m ; ++j ) {
                ans[i][j] = (j > count1);
            }
        }

        // for ( int i = 0 ; i < m ; ++i ) {
        //     for ( int j = 0 ; j < m ; ++j ) {
        //         cout<<ans[i][j]<<" ";
        //     }
        //     cout<<'\n';
        // }
        // cout<<n-2<<'\n';
        ans = matPow(ans, n - 2);

        // for ( int i = 0 ; i < m ; ++i ) {
        //     for ( int j = 0 ; j < m ; ++j ) {
        //         cout<<ans[i][j]<<" ";
        //     }
        //     cout<<'\n';
        // }

        vector<vector<int>> nums(m, vector<int>(m,0));

        for ( int j = l ; j <= r ; ++j ) {
            nums[0][j - l] = j - l;
        }

        // for ( int i = 0 ; i < m ; ++i ) {
        //     cout<<nums[0][i]<<" ";
        // }
        // cout<<'\n';
        nums = matMul(nums,ans);

        long long res = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            // cout<<nums[0][i]<<" ";
            res = (res + nums[0][i])%oo;
        }

        res = res*2LL%oo;
        return res;
    }
};
