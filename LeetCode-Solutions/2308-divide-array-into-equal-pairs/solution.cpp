class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> mark(501,0);
        for ( auto i : nums ) {
            mark[i]++;
        }
        for ( auto i : nums ) {
            if ( mark[i] & 1 ) return false;
        }
        return true;
    }
};
