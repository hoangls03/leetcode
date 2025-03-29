#define ii pair<int,int> 
#define fi first
#define se second
const int oo = 1e9 + 7;
class Solution {
public:
    int countFactors(int n) {
        int count = 0;

        for (long long i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                count++;
                while (n % i == 0) {
                    n /= i;
                }
            }
        }
        if (n > 1) count++;
        return count;
    }
    int powNum( int a, int b ) {
        long long ans = 1;
        if ( b == 1 ) return a;
        if ( b & 1 ) return 1LL*powNum(a,b-1)*a%oo;
        long long p = powNum(a,b/2);
        return p*p%oo;

    }
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<ii> pq;
        vector<int> prime(n);
        for ( int i = 0 ; i < n ; ++i ) {
            prime[i] = countFactors(nums[i]);
            pq.push({nums[i],i});
        }
        vector<int> l(n+1,0),r(n+1,0);
        for ( int i = 0 ; i < n ; ++i ) {
            l[i] = i - 1 ;
            while ( l[i] >= 0 && prime[l[i]] < prime[i] ) l[i] = l[l[i]];
        }
        for ( int i = n - 1; i >= 0 ; --i ) {
            r[i] = i + 1;
            while ( r[i] < n && prime[r[i]] <= prime[i] ) r[i] = r[r[i]];
        }

        int ans = 1;
        while ( pq.size() && k > 0 ) {
            auto u = pq.top();
            pq.pop();

            long long tmp = min(1LL*k,1LL*(u.se - l[u.se])*(r[u.se] - u.se));
            ans = 1LL*ans*powNum(u.fi,tmp)%oo;

            k -= tmp;
        }
        return ans;
    }
};
