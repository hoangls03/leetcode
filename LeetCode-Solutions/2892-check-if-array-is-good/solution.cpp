class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> mark(n + 1,0);
        for ( auto i : nums ) {
            if ( i <= n ) {
                mark[i]++;
            }
        }
        for ( int i = 1 ; i < n - 1; ++i ) {
            if ( mark[i] != 1 ) {
                return false;
            }
        }
        if ( mark[n - 1] != 2 ) return false;
        return true;
    }
};
