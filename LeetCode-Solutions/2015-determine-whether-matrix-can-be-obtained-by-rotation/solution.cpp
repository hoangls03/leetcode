class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>>& grid ) {
        int m = grid.size();
        vector<vector<int>> ans(m,vector<int>(m,0));
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < m ; ++j ) {
                ans[i][j] = grid[m - j - 1][i];
            }
        }
        return ans;
    }
    bool compareMat( vector<vector<int>> mat, vector<vector<int>> target ) {
        int m = mat.size();
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < m ; ++j ) {
                if ( mat[i][j] != target[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        auto ans = mat;
        if ( compareMat(mat,target) ) {
            return true;
        }
        for ( int i = 0 ; i < 3 ; ++i ) {
            ans = rotate(ans);
            if ( compareMat(ans,target) ) {
                return true;
            }
        }
        return false;
    }
};
