class Solution {
public:
    bool check( vector<int>& mark ) {
        return ( mark['a'] >= 1 && mark['b'] >= 1 && mark['c'] >= 1 );
    }
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        vector<int> mark('c' + 1);
        int pos = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            while ( !check(mark) && pos < n ) {
                mark[s[pos]]++;
                pos++;
            }
            if ( check(mark) ) {
                ans += n - pos + 1;
            }
            mark[s[i]]--;
        }
        return ans;
    }
};
