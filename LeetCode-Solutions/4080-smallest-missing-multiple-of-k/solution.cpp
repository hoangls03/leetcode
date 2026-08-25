class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> mark(1005,0);
        for ( auto i : nums ) {
            mark[i] = 1;
        }
        int tmp = k;
        while ( mark[tmp] == 1 ) {
            tmp += k;
        }
        return tmp;
    }
};
