class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        for ( auto i : intervals ) {
            bool ok = true;
            for ( auto j : intervals ) {
                if ( i[0] != j[0] || i[1] != j[1] ) {
                    if ( j[0] <= i[0] && i[1] <= j[1] ) {
                        ok = false;
                        break;
                    }
                }
            }
            ans += ok;
        }
        return ans;
    }
};
