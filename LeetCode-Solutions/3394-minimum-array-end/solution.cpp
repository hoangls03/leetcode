class Solution {
public:
    long long pow2( long long n ) {
        long long ans = 1;
        for ( int i = 1 ; i <= n ; ++i ) {
            ans *= 2;
        }
        return ans;
    }
    long long minEnd(int n, int x) {
       int temp = x;
       vector<int> mark(64,0);
       int count = 0;
       while ( temp > 0 ) {
            int m = log2(temp);
            mark[m] = 1;
            temp -= ( 1 << m );
       }
       temp = n - 1;
       vector<int> val(27,0); 
       while ( temp > 0 ) {
            int m = log2(temp);
            val[m] = 1;
            temp -= ( 1 << m );
       } 
       long long ans = x;
       for ( int i = 0 ; i <= 63 ; ++i ) {
            if ( mark[i] == 0 ) {
                if ( count <= 26 && val[count] == 1 ) {
                    ans += pow2(i);
                }
                count++;
            }
       }
       return ans;
    }
};
