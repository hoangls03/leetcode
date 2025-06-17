const int oo = 1e9 + 7;
class Solution {
public:
    int power( int a, int b, int c ) {
        if ( b == 0 ) return 1;
        int p = power(a,b/2,c);
        p = 1LL*p*p%c;
        if ( b & 1 ) p = 1LL*p*a%c;
        return p;
    }
    int countGoodArrays(int n, int m, int k) {
        vector<int> fact(n,0);
        vector<int> inv(n,0);
        fact[0] = 1;
        inv[0] = 1;
        for ( int i = 1 ; i < n ; ++i ) {
            fact[i] = 1LL*fact[i-1]*i%oo;
        }
        inv[n-k-1] = power(fact[n-k-1],oo-2,oo);
        inv[k] = power(fact[k],oo-2,oo);
        int ans = 1LL*m*fact[n-1]%oo*inv[n-k-1]%oo*inv[k]%oo*power(m-1,n-k-1,oo)%oo;
        return ans;
    }
};
