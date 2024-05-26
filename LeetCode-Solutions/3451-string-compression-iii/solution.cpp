class Solution {
public:
    string compressedString(string word) {
        string ans;
        int n = word.size();
        word = " " + word;
        int count = 1;
        for ( int i = 2 ; i <= n ; ++i ) {
            if ( word[i] != word[i-1] || count == 9 ) {
                ans += count + '0';
                ans += word[i-1];
                count = 1;
            } else {
                count++;
            }
        }
        ans += count + '0';
        ans += word[n];
        return ans;
    }
};
