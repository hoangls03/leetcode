#define ii pair<int,int>
#define fi first
#define se second
class Solution {
public:
    struct cmp{
        bool operator() (ii a,ii b) {return a.fi*b.se <= b.fi*a.se;}
    };
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<ii,vector<ii>,cmp> pq;
        int n = arr.size();
        for ( int i = 0 ; i < n - 1 ; ++i ) {
            for ( int j = i + 1 ; j < n ; ++j ) {
                pq.push({arr[i],arr[j]});
                if ( pq.size() > k ) {
                    pq.pop();
                }
            }
        }
        vector<int> ans;
        ans.push_back(pq.top().fi);
        ans.push_back(pq.top().se);
        return ans;
    }
};
