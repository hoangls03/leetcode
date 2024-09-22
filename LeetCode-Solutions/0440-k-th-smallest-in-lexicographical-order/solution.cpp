class Solution {
public:
    int cal( long long val, int n ) {
        int sum = 1;
        val = val*10;
        long long temp = 10;
        while ( val <= n ) {
            sum += min(temp,n-val+1);
            val = val*10;
            temp *= 10;
        }
        return sum;
    }
    int findKthNumber(int n, int k) {
        long long val = 1;
        k--;
        while ( k > 0 ) {
            int step = cal(val,n);
            if ( step <= k ) {
                val++;
                k -= step;
            } else {
                val *= 10;
                k--;
            }
        }
        return val;
    }
};
