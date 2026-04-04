class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int lenS = encodedText.size();
        int n = lenS/rows;
        int m = rows;
        vector<vector<char>> grid(m,vector<char>(n,'*'));
        int iter = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                grid[i][j] = encodedText[iter];
                iter++;
            }
        } 
        string ans = "";
        for ( int j = 0 ; j < n ; ++j ) {
            for ( int i = 0 ; i < m ; ++i ) {
                if ( i + j < n ) {
                    ans += grid[i][i + j];
                }
            }
        }
        for ( int i = 0 ; i < ans.size() ; ++i ) {
            if ( ans[i] != ' ' ) {
                iter = i;
            }
        }
        ans = ans.substr(0,iter + 1);
        return ans;
    }
};
