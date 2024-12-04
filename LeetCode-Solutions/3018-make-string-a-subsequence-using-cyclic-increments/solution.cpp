class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        int pos = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            if ( pos < n && (str1[i] - 'a' + 1)%26 + 'a' == str2[pos] || str1[i] == str2[pos] ) {
                pos++;
            } 
        }
        if ( pos == n ) return true;
        return false;
    }
};
