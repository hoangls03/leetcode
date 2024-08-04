const int ax[] = {-1,0,0,1};
const int ay[] = {0,-1,1,0};
const int dx[] = {-1,-1,1,1};
const int dy[] = {-1,1,-1,1}; 
class neighborSum {
public:
    vector<vector<int>> a;
    neighborSum(vector<vector<int>>& grid) {
       a = grid; 
    }
    
    int adjacentSum(int value) {
        int m = a.size();
        int n = a[0].size();
        int ans = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( a[i][j] == value ) {
                    for ( int k = 0 ; k < 4 ; ++k ) {
                        int x = i + ax[k];
                        int y = j + ay[k];
                        if ( 0 <= x && x < m && 0 <= y && y < n ) {
                            ans += a[x][y];
                        }
                    }
                }
            }
        }
        return ans;
    }
    
    int diagonalSum(int value) {
        int m = a.size();
        int n = a[0].size();
        int ans = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( a[i][j] == value ) {
                    for ( int k = 0 ; k < 4 ; ++k ) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if ( 0 <= x && x < m && 0 <= y && y < n ) {
                            ans += a[x][y];
                        }
                    }
                }
            }
        }
        return ans;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
