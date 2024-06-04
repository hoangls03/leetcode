class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        int ans = 0;
        bool check = false;
        vector<int> count('z'+5,0);
        for ( int i = 0 ; i < n ; ++i ) {
            count[s[i]]++;
        }
        for ( int i = 'A' ; i <= 'z' ; ++i ) {
            ans += (count[i]/2)*2;
            if ( count[i] & 1 ) check = true;
        }
        return ans + check;
    }
};
