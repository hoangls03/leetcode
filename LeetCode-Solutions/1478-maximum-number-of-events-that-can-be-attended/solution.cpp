class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int pos = 0;
        int ans = 0;
        int n = events.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        for ( int i = 1 ; i <= 1e5 ; ++i ) {
            while ( pos < n && i >= events[pos][0] ) {
                pq.push(events[pos][1]);
                pos++;
            }
            while ( pq.size() && i > pq.top() ) {
                pq.pop();
            }
            if ( pq.size() ) {
                ans++;
                pq.pop();
            }
        }
        return ans;
    }
};
