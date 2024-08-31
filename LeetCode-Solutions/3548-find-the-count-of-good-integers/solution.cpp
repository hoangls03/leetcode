class Solution {
public:
    int bt[10];
    long long C( int n, int k) {
        long long nfac = 1;
        for ( int i = 1 ; i <= n ; ++i ) {
            nfac *= i;
        }
        long long nRfac = 1;
        for ( int i = 1 ; i <= n - k ; ++i ) 
            nRfac *= i;
        long  long kfac = 1;
        for ( int i = 1 ; i <= k ; ++i ) {
            kfac *= i;
        }
        nfac /= nRfac;
        nfac /= kfac;
        return nfac;
    }
    map<long long,int> mp;
    void write( int m, int n, int k, long long& ans) {
        /*for ( int i = 0 ; i < m ; ++i ) {
            cout<<bt[i];
        }
        cout<<'\n';
        */
        int bt2[11];
        int o = 0;
        if ( bt[0] != 0 ) {
            long long temp = 0;
            for ( int i = 0 ; i < m ; ++i ) {
                temp = temp*10 + bt[i];
                bt2[o++] = bt[i];
            }
            int pos = m - 1;
            if ( n & 1 ) {
                pos--;
            }
            for ( int i = pos ; i >= 0 ; --i ) {
                temp = temp*10 + bt[i]; 
                bt2[o++] = bt[i];
            }
            if ( temp % k == 0 ) {
                sort(bt2,bt2+o);
                long long temp = 0;
                int mark[10];
                for ( int i = 0 ; i <= 9 ; ++i )
                    mark[i] = 0;
                for ( int i = 0 ; i < n ; ++i ) {
                    temp = temp*10 + bt2[i];
                    mark[bt2[i]]++;
                }
                if ( mp[temp] == 0 ) {
                    long long tp = 1;
                    long long num = n;
                    for ( int i = 0 ; i <= 9 ; ++i ) {
                        if ( mark[i] != 0 ) {
                            if ( i == 0 ) tp *= C(num-1,mark[i]);
                            else tp *= C(num,mark[i]);
                            num -= mark[i];
                        }
                    }
                    ans += tp;
                }
                mp[temp]++;
               
            }
        }
    }
    void bk( int i , int m, int n, int k, long long& ans ) {
        for ( int j = 0 ; j <= 9 ; ++j ) {
            if ( i == m ) {
                write(m,n,k,ans);
                return ;
            }
            else if ( i < m ) {
                bt[i] = j;
                bk(i+1,m,n,k,ans);
            }
        }
    }
    long long countGoodIntegers(int n, int k) {
        int temp = n/2;
        long long ans = 0;
        if ( n & 1 ) temp++;
        mp.clear();
        bk(0,temp,n,k,ans);
        return ans;
    }
};
