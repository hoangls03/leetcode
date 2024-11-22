class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string,int> mp;
        int ans = 0;
        for ( auto r : matrix ) {
            string s = "";
            for ( auto i : r ) {
                if ( r[0] == 0 ) {
                    s += to_string(i);
                } else {
                    s += to_string(i^1);
                }
            }
            mp[s]++;
            ans = max(ans,mp[s]);
        }
        return ans;
    }
};
