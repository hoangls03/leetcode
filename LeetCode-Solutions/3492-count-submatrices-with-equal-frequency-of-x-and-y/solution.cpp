class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> countX(m,vector<int>(n,0)), countY(m,vector<int>(n,0));
        int ans = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            int sumX = 0, sumY = 0;
            for ( int j = 0 ; j < n ; ++j ) {
                sumX += (grid[i][j] == 'X');
                sumY += (grid[i][j] == 'Y');
                countX[i][j] = (i > 0) ? countX[i-1][j] : 0;
                countY[i][j] = (i > 0) ? countY[i-1][j] : 0;
                countX[i][j] += sumX;
                countY[i][j] += sumY;
                if ( countX[i][j] >= 1 && countX[i][j] == countY[i][j] ) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
