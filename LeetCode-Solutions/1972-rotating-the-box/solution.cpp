class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size(); 
        for ( int i = 0 ; i < m ; ++i ) {
            int pos = n - 1;
            for ( int j = n - 1 ; j >= 0 ; --j ) {
                if ( box[i][j] == '#' ) {
                    box[i][j] = '.';
                    box[i][pos] = '#';
                    pos--;
                } else if (box[i][j] == '*'){
                    pos = j - 1;
                }
            }
        }
        
        vector<vector<char>> ans(n,vector<char>(m));
        for ( int j = 0 ; j < n ; ++j ) {
            for ( int i = m - 1 ; i >= 0 ; --i ) {
                ans[j][m-i-1] = box[i][j];
            }
        }
        return ans;
    }
};
