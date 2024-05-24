class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        vector<int> win(1e5+1,0),loose(1e5+1,0);
        for ( int i = 0 ; i < n ; ++i ) {
            win[matches[i][0]]++;
            loose[matches[i][1]]++;
        }
        vector<vector<int>> ans(2);
        for ( int i = 1 ; i <= 1e5 ; ++i ) {
            if ( loose[i] == 0 && win[i] != 0 ) {
                ans[0].push_back(i);
            }
            if ( loose[i] == 1 ) {
                ans[1].push_back(i);
            }
        }
        return ans;
    }
};
