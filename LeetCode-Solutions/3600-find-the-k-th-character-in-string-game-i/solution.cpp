class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while ( s.size() < k ) {
            int n = s.size();
            for ( int i = 0  ; i < n; ++i ) {
                s += (s[i] + 1 -'a')%26 + 'a';
            }
        }
        return s[k-1];
    }
};
