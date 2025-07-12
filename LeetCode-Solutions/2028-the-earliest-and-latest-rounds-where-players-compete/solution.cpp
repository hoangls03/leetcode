class Solution {
public:
    void fight( vector<int> players, vector<int>& mark, int& minRound, int& maxRound, int round, map<vector<int>,int>& mp) {
        int n = players.size();
        vector<int> save;
        save.push_back(n);
        for ( int i = 0 ; i < n ; ++i ) {
            if ( mark[players[i]] == 1 ) {
                save.push_back(i);
            }
        } 
        if ( mp[save] == 1 ) return ;
        mp[save] = 1;
        for ( int i = 0 ; i < n/2 ; ++i ) {
            if ( i != n - i - 1 && mark[players[i]] * mark[players[n-i-1]] == 1 ) {
                minRound = min(minRound,round);
                maxRound = max(maxRound,round);
            }
        }
        int m = n/2;
        
        for ( int i = 0 ; i < (1 << m) ; ++i ) {
            vector<int> result;
            for ( int j = 0 ; j < m ; ++j ) {
                result.push_back((i >> j) & 1);
            }
            bool check = true;
            vector<int> nextPlayers;
            
            for ( int j = 0 ; j < m && check; ++j ) {
                if ( result[j] == 1 ) {
                    if ( mark[players[n-j-1]] == 1 ) {
                        check = false;
                    }
                    nextPlayers.push_back(players[j]);
                }
            }
            if ( n & 1 ) nextPlayers.push_back(players[m]);
            for ( int j = m - 1; j >= 0 && check ; --j ) {
                if ( result[j] == 0 ) {
                    if ( mark[players[j]] == 1 ) {
                        check = false;
                    }
                    nextPlayers.push_back(players[n-j-1]);
                } 
            }
            if ( check ) {
                fight(nextPlayers,mark,minRound,maxRound,round + 1,mp);
            }
        }
        return ;
    }
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        vector<int> mark(30,0);
        mark[firstPlayer] = 1;
        mark[secondPlayer] = 1;
        map<vector<int>,int> mp;
        vector<int> players;
        for ( int i = 1 ; i <= n ; ++i ) {
            players.push_back(i);
        }
        int minRound = n, maxRound = 1;
        fight(players,mark,minRound,maxRound,1,mp);
        vector<int> ans = {minRound,maxRound};
        return ans;
    }
};
