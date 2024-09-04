#define ii pair<int,int>
#define fi first
#define se second
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<ii,int> mp;
        mp.clear();
        for ( auto o : obstacles ) {
            mp[{o[0],o[1]}] = 1;
        }
        int direct = 0;
        ii cur = {0,0};
        int ans = 0;
        for ( auto i : commands ) {
            if ( i == -1 ) {
                direct = (direct + 1)%4;
                continue;
            }
            if ( i == -2 ) {
                direct = (direct + 3)%4;
                continue;
            }
            int pos = 0;
            for ( int j = 1 ; j <= i ; ++j ) {
                ii v = {cur.fi + j*dx[direct],cur.se + j*dy[direct]};
                if ( mp[v] == 1 ) {
                    break;
                }
                pos = j; 
            }
            cur.fi += pos*dx[direct];
            cur.se += pos*dy[direct];
            ans = max(ans,cur.fi*cur.fi + cur.se*cur.se);
        }
        return ans;
    }
};
