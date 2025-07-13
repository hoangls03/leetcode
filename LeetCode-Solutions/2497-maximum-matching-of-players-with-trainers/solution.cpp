class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size();
        int m = trainers.size();
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int pos = m - 1;
        int ans = 0;
        for ( int i = n - 1 ; i >= 0 ; --i ) {
            if ( pos >= 0 && players[i] <= trainers[pos] ) {
                ans++;
                pos--;
            }
        }
        return ans;
    }
};
