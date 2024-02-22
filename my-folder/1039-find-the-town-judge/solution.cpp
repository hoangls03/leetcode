class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int betrust[n+5],trusted[n+5];
        for ( int i = 1 ; i <= n ; ++i ) {
            trusted[i] = 0;
            betrust[i] = 0;
        }
        for ( int i = 0 ; i < trust.size() ; ++i ) {
            betrust[trust[i][1]]++;
            trusted[trust[i][0]]++;
        }
        int ans = -1;
        for ( int i = 1 ; i <= n ; ++i ) {
            if ( betrust[i] == n - 1 && trusted[i] == 0 ) ans = i;
        }
        return ans;
    }
};
