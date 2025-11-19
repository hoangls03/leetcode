class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        vector<int> mark(2005,0);
        for ( auto i : nums ) {
            mark[i]++;
        }
        while ( mark[original] != 0 ) {
            original *= 2;
        }
        return original;
    }
};
