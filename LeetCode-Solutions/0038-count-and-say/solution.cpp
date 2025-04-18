class Solution {
public:
    string RLE( int n ) {
        if ( n == 1 ) return "1";
        string s = RLE(n-1);
        int count = 1;
        string ans = "";
        int m = s.size();
        for ( int i = 1 ; i < m ; ++i ) {
            if ( s[i] != s[i-1] ) {
                ans += to_string(count);
                ans += s[i-1];
                count = 1;
            } else {
                count++;
            }
        }
        ans += to_string(count);
        ans += s[m-1];
        return ans; 
    }
    string countAndSay(int n) {
        return RLE(n); 
    }
};
