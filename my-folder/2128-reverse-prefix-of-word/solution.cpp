class Solution {
public:
    string reversePrefix(string word, char ch) {
        int pos = 0;
        int n = word.size();
        for ( int i = n - 1 ; i >= 0 ; --i ) {
            if ( word[i] == ch ) {
                pos = i;
            }
        }
        string ans;
        for ( int i = pos ; i >= 0 ; --i ) {
            ans += word[i];
        }
        for ( int i = pos + 1 ; i < n ; ++i ) {
            ans += word[i];
        }
        return ans;
    }
};
