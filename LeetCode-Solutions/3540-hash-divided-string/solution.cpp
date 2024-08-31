class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.size();
        int length = 0;
        long long temp = 0;
        string ans = "";
        for ( int i = 0 ; i < n ; ++i ) {
            length++;
            temp = temp + s[i] - 'a';
            if ( length == k ) {
                temp %= 26;
                ans += temp + 'a';
                temp = 0;
                length = 0;
            }
        }
        return ans;
    }
};
