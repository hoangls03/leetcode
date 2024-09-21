class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        int val = 1;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( val > n ) {
                while ( val >= n ) {
                    val /= 10;
                }
                val++;
                while ( val % 10 == 0 ) {
                    val /= 10;
                }
            }
            if ( val <= n ) {
                ans[i] = val;
                val *= 10;
            } 
        }
        return ans;
    }
};
