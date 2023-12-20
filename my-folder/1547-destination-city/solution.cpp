class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int m = paths.size();
        int n = paths[0].size();
        map<string,int> mp;
        for ( int i = 0 ; i < m ; ++i ) {
            mp[paths[i][0]] = 1;
        }
        for ( int i = 0 ; i < m ; ++i ) {
            if ( mp[paths[i][1]] == 0 ) {
                mp.clear();
                return paths[i][1];
            }
        }
        return "";
    }
};
