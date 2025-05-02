class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();

        vector<int> mark(n,0);

        int res = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( dominoes[i] == 'R' ) {
                res = n;
            } else if ( dominoes[i] == 'L' ) {
                res = 0;
            } else {
                res = max(res-1,0);
            }
            mark[i] += res;
        }

        res = 0;
        for ( int i = n - 1 ; i >= 0 ; --i ) {
            if ( dominoes[i] == 'L' ) {
                res = n;
            } else if ( dominoes[i] == 'R' ) {
                res = 0;
            } else {
                res = max(res-1,0);
            }
            mark[i] -= res;
        }

        string ans = "";
        for ( int i = 0 ; i < n ; ++i ) {
            if ( mark[i] < 0 ) {
                ans += 'L';
            } else if ( mark[i] > 0 ) {
                ans += 'R';
            } else {
                ans += '.';
            }
        }
        return ans;
    }
};
