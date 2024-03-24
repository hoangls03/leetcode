class Solution {
public:
    int minOperations(int k) {
        int ans = 1e9;
        for ( int i = 1 ; i <= k ; ++i ) {
            int temp = k/i;
            
            if ( k % i == 0 ) ans = min(ans,temp - 1 + i-1);
            else ans = min(ans,temp + i-1);
        }
        if ( k == 1 ) ans = 0;
        return ans;
    }
};
