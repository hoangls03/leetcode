class Solution {
public:
    int minimizeXor(int num1, int num2) {
        vector<int> mark(33,0);

        while ( num1 > 0 ) {
            int temp = log2(num1);
            mark[temp] = 1;
            num1 -= ( 1 << temp);
        }
        
        int countBit = 0;
        while ( num2 > 0 ) {
            int temp = log2(num2);
            countBit++;
            num2 -= ( 1 << temp );
        }
        for ( int i = 32 ; i >= 0 ; --i ) {
            if ( countBit > 0 && mark[i] == 1 ) {
                mark[i] = 2;
                countBit--;
            }
        }
        for ( int i = 0 ; i <= 32 ; ++i ) {
            if ( mark[i] == 0 && countBit ) {
                mark[i] = 3;
                countBit--;
            }
        }

        int ans = 0;
        for ( int i = 0 ; i <= 32 ; ++i ) {
            if ( mark[i] >= 2  ) {
                ans += ( 1 << i );
            }
        }
        return ans;
    }
};
