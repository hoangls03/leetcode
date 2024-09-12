class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mark[26];
        for ( int i = 0 ; i < 26 ; ++i ) {
            mark[i] = 0;
        }
        for ( auto i : allowed ) {
            mark[i-'a'] = 1;
        }
        int ans = 0;
        for ( auto s : words ) {
            bool check = true;
            for ( auto i : s ) {
                if ( mark[i-'a'] == 0 ) {
                    check  = false;
                }
            }
            ans += check;
        }
        return ans;
    }
};
