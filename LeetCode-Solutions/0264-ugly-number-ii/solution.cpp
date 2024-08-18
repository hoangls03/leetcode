const long long primes[] = {2,3,5};
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        map<long long,int> mp;
        pq.push(1);
        mp[1] = 1;
        int count = 1;
        int val;
        while ( count <= n ) {
            val = pq.top();
            pq.pop();
            count++;
            for ( int i = 0 ; i < 3 ; ++i ) {
                long long temp = val*primes[i];
                if ( mp[temp] == 0 ) {
                    pq.push(temp);
                    mp[temp] = 1;
                }
            }
        }
        return val;
    }
};
