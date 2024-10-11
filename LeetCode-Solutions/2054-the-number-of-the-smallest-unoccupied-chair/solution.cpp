#define ii pair<int,int>
#define fi first
#define se second
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<vector<ii>> vt(1e5+1);
        for ( int i = 0 ; i < n ; ++i ) {
            vt[times[i][1]].push_back({1,i});
        }
        for ( int i = 0 ; i < n ; ++i ) {
            vt[times[i][0]].push_back({0,i});
        }
        int ans;
        priority_queue<int,vector<int>,greater<int>> pq;
        for ( int i = 0 ; i <= n ; ++i ) {
            pq.push(i);
        }
        vector<int> mark(n+1);
       
        for ( int i = 1 ; i <= 1e5 ; ++i ) {
            for ( auto u : vt[i] ) {
                if ( u.fi == 1 ) {
                    pq.push(mark[u.se]);
                } else {

                    mark[u.se] = pq.top();
                    if ( u.se == targetFriend ) return pq.top();
                    pq.pop();
                }
            }
        }
        return 0;
    }
};
