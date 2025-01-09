class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int m = pref.size();
        int ans = 0;
        for ( auto word : words ) {
            int n = word.size();
            if ( n < m ) continue;
            if ( word.substr(0,m) == pref ) ans++;
        }
        return ans;
    }
};
