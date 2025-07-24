class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        vector<int> mark(101,0);
        for ( auto i : nums ) {
            mark[i]++;
        }
        for ( int i = 1 ; i <= 100 ; ++i ) {
            if ( mark[i] > 2 ) {
                return false;
            }
        }
        return true;
    }
};
