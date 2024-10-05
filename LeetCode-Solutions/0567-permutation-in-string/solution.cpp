class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int> count(26,0);
        vector<vector<int>> mark(m,vector<int>(26,0));
        if ( n > m ) return false;
        for ( auto i : s1 ) {
            count[i-'a']++;
        } 
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < 26 ; ++j ) {
                mark[i][j] = i == 0 ? 0 : mark[i-1][j];
            }
            mark[i][s2[i]-'a']++;
        }
        for ( int i = 0 ; i <= m - n ; ++i ) {
            bool check = true;
            for ( int j = 0 ; j < 26 ; ++j ) {
                int l = i == 0 ? 0 : mark[i-1][j];
                if ( count[j] != mark[i+n-1][j] - l ) {
                    check = false;
                    break;
                }
            }
           
            if ( check ) return true;
        }
        return false;
    }
};
