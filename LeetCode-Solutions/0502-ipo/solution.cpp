#define ii pair<int,int>
#define fi first
#define se second
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        vector<ii> a;
        int n = profits.size();
        for ( int i = 0 ; i < n ; ++i ) {
            a.push_back({capital[i],profits[i]});
        }
        sort(a.begin(),a.end());
        for ( int i = 0 ; i < n && k > 0; ++i ) {
            if ( w >= a[i].fi ) {
                pq.push(a[i].se);
            } else {
                if ( pq.size() == 0 ) return w;
                while ( w < a[i].fi && k > 0 && pq.size() ) {
                    w += pq.top();
                    pq.pop();
                    k--;
                }
                if ( w < a[i].fi ) return w;
                pq.push(a[i].se);
            }
        }
        while ( k > 0 && pq.size() ) {
            w += pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};
