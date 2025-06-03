class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> q;
        int n = candies.size();
        vector<int> have(n,0);
        vector<int> mark(n,0);
        for ( auto i : initialBoxes ) {
            if ( status[i] == 1 ) {
                q.push(i);
                have[i] = 2;
            } else have[i] = 1;
        }
        int ans = 0;
        while ( q.size() ) {
            int u = q.front();
            ans += candies[u];
            have[u] = 2;
            q.pop();
            for ( auto i : keys[u] ) {
                status[i] = 1;
            }
            for ( auto i : containedBoxes[u] ) {
                if ( have[i] == 0 ) {
                    have[i] = 1;
                }
            }
            for ( int i = 0 ; i < n ; ++i ) {
                if ( have[i] == 1 && status[i] == 1 ) {
                    q.push(i);
                    mark[i] = 1;
                    have[i] = 2;
                }
            }
        }
        return ans;
    }
};
