class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int pos = n - 1;

        vector<int> suf(m + 1,0);
        for ( int i = m - 1 ; i >= 0 ; --i ) {
            if ( i != m - 1 ) {
                suf[i] = suf[i+1];
            }
            if ( pos >= 0 && word1[i] == word2[pos] ) {
                pos--;
                suf[i]++;
            }
        }

        vector<int> ans;
        pos = 0;
        bool ok = true;
        for ( int i = 0 ; i < m ; ++i ) {
            if ( pos < n && word1[i] == word2[pos] ) {
                ans.push_back(i);
                pos++;
            } else {
                if ( pos < n && suf[i+1] >= n - pos - 1 && ok ) {
                    ans.push_back(i);
                    ok = false;
                    pos++;
                }
            }
        }

        if ( pos < n ) {
            return {};
        }
        return ans;
    }
};
