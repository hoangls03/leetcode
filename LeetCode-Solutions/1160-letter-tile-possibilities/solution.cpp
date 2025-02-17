class Solution {
public:
    int numTilePossibilities(string tiles) {
        map<string,int> mp;
        int n = tiles.size();
        int ans = 0;
        string s = "";
        mp.clear();
        for ( int i = 0 ; i < n ; ++i ) {
            s += tiles[i];
            if ( mp[s] == 0 ) {
                ans++;
                mp[s] = 1;
            }
        }
        vector<int> pos;
        for ( int i = 0 ; i < n ; ++i ) {
            pos.push_back(i);
        }
        while ( next_permutation(pos.begin(),pos.end()) ) {
            s = "";
            for ( int i = 0 ; i < n ; ++i ) {
                s += tiles[pos[i]];
                if ( mp[s] == 0 ) {
                    ans++;
                    mp[s] = 1;
                }
            }
        }
        return ans;
    }
};
