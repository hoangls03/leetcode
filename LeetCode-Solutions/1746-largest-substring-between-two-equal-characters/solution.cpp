class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        vector<int> mark(30,-1);
        int ans = -1;
        for ( int i = n-1 ; i >= 0 ; --i ) {
            if ( mark[s[i]-'a'] != -1 ) {
                ans = max(ans,mark[s[i]-'a'] - i-1);
            }
            if ( mark[s[i]-'a'] == -1 ) {
                mark[s[i]-'a'] = i;
            }
        }
        return ans;
    }
};
