#define ii pair<double,int>
#define fi first
#define se second
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        priority_queue<int> pq;
        while ( pq.size() ) {
            pq.pop();
        }
        int n = quality.size();
        vector<ii> worker(n);
        worker.clear();
        for ( int i = 0 ; i < n ; ++i ) {
            worker.push_back({double(wage[i])/double(quality[i]),quality[i]});
        }
        sort(worker.begin(),worker.end());
        for ( auto i : worker ) {
            //cout<<i.fi<<" "<<i.se<<'\n';
        }
        double sum = 0;
        double rate = 0;
        double ans = 1e18;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( pq.size() >= k ) {
                ans = min(ans,rate*sum);
                rate = max(rate,worker[i].fi);
                sum -= pq.top();
                pq.pop();
                sum += worker[i].se;
                pq.push(worker[i].se);
                
            } else {
                sum += worker[i].se;
                rate = max(rate,worker[i].fi);
                pq.push(worker[i].se);
            }
        }
        ans = min(ans,rate*sum);
        return ans;
    }
};
