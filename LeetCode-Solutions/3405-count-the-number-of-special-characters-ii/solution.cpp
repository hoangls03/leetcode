class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> mark('z' + 1, -1);
        int n = word.size();
        for ( int i = 0 ; i < n ; ++i ) {
            if ( 'a' <= word[i] && word[i] <= 'z' ) {
                mark[word[i]] = i;
            } else {
                if ( mark[word[i]] == -1 ) {
                    mark[word[i]] = i;
                }
            }
        }
        int ans = 0;
        for ( int i = 'a' ; i <= 'z' ; ++i ) {
            int diff = 'A' - 'a';
            if ( mark[i] != -1 && mark[i + diff] != -1 && mark[i] < mark[i+diff]) {
                ans++;
            }
        }
        return ans;
    }
};
