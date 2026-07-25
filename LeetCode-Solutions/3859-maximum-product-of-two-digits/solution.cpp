class Solution {
public:
    int maxProduct(int n) {
        vector<int> mark(10,0);
        while ( n > 0 ) {
            mark[n%10]++;
            n /= 10;
        }

        for ( int i = 9 ; i >= 0 ; --i ) {
            if ( mark[i] != 0 ) {
                mark[i]--;
                for ( int j = 9 ; j >= 0 ; --j ) {
                    if ( mark[j] != 0 ) {
                        return i*j;
                    }
                }
            }
        }

        return 0;
    }
};
