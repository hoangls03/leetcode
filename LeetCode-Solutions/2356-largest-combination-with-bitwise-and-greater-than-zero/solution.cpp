class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> mark(24,0);
        for ( auto i : candidates ) {
            while ( i > 0 ) {
                int temp = log2(i);
                mark[temp]++;
                i -= ( 1 << temp );
            }
        }
        int ans = 1;
        for ( int i = 0 ; i <= 23 ; ++i ) {
            ans = max(ans,mark[i]);
        }
        return ans;
    }
};
