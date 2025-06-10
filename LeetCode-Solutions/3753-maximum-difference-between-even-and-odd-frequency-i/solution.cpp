class Solution {
public:
    int maxDifference(string s) {
        vector<int> mark('z' + 1,0);
        for ( auto i : s ) {
            mark[i]++;
        }
        int n = s.size();
        int odd = 0;
        int even = n + 1;
        for ( int i = 'a' ; i <= 'z' ; ++i ) {
            if ( mark[i] != 0 ) {
                if ( mark[i] & 1 ) odd = max(odd,mark[i]);
                else even = min(even,mark[i]);
            }
        }
        return odd - even;
    }
};
