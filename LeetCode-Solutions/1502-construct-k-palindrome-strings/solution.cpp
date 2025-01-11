class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> mark('z' + 1);
        for ( auto i : s ) {
            mark[i]++;
        }
        int odd = 0;
        for ( int i = 'a' ; i <= 'z' ; ++i ) {
            odd += (mark[i] & 1);
        }
        if ( odd > k || k > s.size() ) return false;
        return true;
    }
};
