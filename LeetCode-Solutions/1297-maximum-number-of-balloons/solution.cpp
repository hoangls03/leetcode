class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> countCh('z' + 1);
        for ( auto i : text ) {
            countCh[i]++;
        }
        int ans = 0;
        string s = "balloon";
        while ( true ) {
            for ( auto i : s ) {
                if ( countCh[i] == 0 ) {
                    return ans;
                }
                countCh[i]--;
            }
            ans++;
        }
    }
};
