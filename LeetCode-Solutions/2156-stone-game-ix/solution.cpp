class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> mark(5,0);
        for ( auto i : stones ) {
            mark[i%3]++;
        }
        if ( mark[0] % 2 == 0 ) {
            if ( min(mark[1],mark[2]) >= 1 ) {
                return true;
            }
            return false;
        }
        int val = abs(mark[1] - mark[2]);
        return val > 2;
    }
};
