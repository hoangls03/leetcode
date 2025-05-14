const int oo = 1e9 + 7;
class Solution {
    struct matrix {
        int row, col;
        vector<vector<int>> c;
    };
public:
    
    matrix matrixMul(matrix a, matrix b) {
        matrix ans;
        for ( int i = 0 ; i < a.row ; ++i ) {
            vector<int> tmp;
            for ( int j = 0 ; j < b.col ; ++j ) {
                int res = 0;
                for ( int z = 0 ; z < a.col ; ++z ) {
                    res = (1LL*res + 1LL*a.c[i][z]*b.c[z][j]%oo)%oo;
                }
                tmp.push_back(res);
            }
            ans.c.push_back(tmp);
        }
        ans.row = a.row;
        ans.col = b.col;
        return ans;
    }
    matrix matrixPow( matrix a, int n ) {
        if ( n == 0 ) {
            matrix b;
            b.row = a.row;
            b.col = a.col;
            for ( int i = 0 ; i < b.row ; ++i ) {
                vector<int> tmp;
                for ( int j = 0 ; j < b.col ; ++j ) {
                    if ( i == j ) {
                        tmp.push_back(1);
                    } else {
                        tmp.push_back(0);
                    }
                }
                b.c.push_back(tmp);
            }
            return b;
        }
        if ( n == 1 ) {
            return a;
        }
        matrix p = matrixPow(a,n/2);
        p = matrixMul(p,p);
        if ( n & 1 ) {
            p = matrixMul(p,a);
        }
        return p;
    }
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<int>> val(26,vector<int>(26,0));
        for ( int i = 0 ; i < 26 ; ++i ) {
            for ( int j = 1 ; j <= nums[i] ; ++j ) {
                int cur = (i + j)%26;
                val[i][cur]++;
            }
        }
        vector<vector<int>> occur(1,vector<int>(26,0));
        for ( auto i : s ) {
            occur[0][i-'a']++;
        }
        matrix a;
        a.row = 1;
        a.col = 26;
        a.c = occur;
        matrix b;
        b.row = 26;
        b.col = 26;
        b.c = val;
        b = matrixPow(b,t);
        matrix ans = matrixMul(a,b);
        int res = 0;
        for ( int i = 0 ; i < 26 ; ++i ) {
            res = (1LL*res + ans.c[0][i])%oo;
        }
        return res;
    }
};
