class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<vector<int>> countR('z' + 1,vector<int>(n + 1,0));
        for ( int i = n - 1 ; i >= 0 ; --i ) {
            for ( int j = 'a' ; j <= 'z' ; ++j ) {
                countR[j][i] = countR[j][i+1];
            }
            countR[s[i]][i]++;
        }
        int ans = 0;
        vector<vector<int>> mark('z' + 1,vector<int>('z'+1,0));
        vector<int> countL('z' + 1);
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 'a' ; j <= 'z' ; ++j ) {
                if ( countL[j] && countR[j][i+1] && mark[j][s[i]] == 0 ) {
                    ans++;
                    mark[j][s[i]]++;
                }
            }
            countL[s[i]]++;
        }
        return ans;
    }
};
