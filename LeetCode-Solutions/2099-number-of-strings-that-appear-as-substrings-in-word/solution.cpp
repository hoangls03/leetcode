class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int m = word.size();
        int ans = 0;
        for ( auto s : patterns ) {
            int n = s.size();
            for ( int i = 0 ; i <= m - n ; ++i ) {
                if ( word.substr(i,n) == s ) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
