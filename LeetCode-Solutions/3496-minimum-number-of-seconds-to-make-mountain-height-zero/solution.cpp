#define ii pair<long long,int>
#define fi first
#define se second
class Solution {
public:
    long long cal( long long n ) {
        return n*(n+1)/2;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long ans = 0;
        priority_queue<ii,vector<ii>,greater<ii>> pq;
        map<long long,int> mp;
        mp.clear();
        for ( int i = 0 ; i < workerTimes.size() ; ++i ) {
            pq.push({workerTimes[i],i});
            mp[i] = 1;
        }
        while ( mountainHeight > 0 ) {
            auto temp = pq.top();
            pq.pop();
            ans = max(temp.fi,ans);
            mp[temp.se]++;
            pq.push({workerTimes[temp.se]*cal((mp[temp.se])),temp.se});
            mountainHeight--;
        }
        return ans;
    }
};
