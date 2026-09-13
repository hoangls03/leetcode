const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        map<vector<int>,int> mp;
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                for ( int u = 0 ; u < n ; ++u ) {
                    for ( int v = 0 ; v < n ; ++v ) {
                        if ( img1[i][j] == 1 && img2[u][v] == 1 ) {
                           mp[{u-i,v-j}]++;
                           ans = max(ans,mp[{u-i,v-j}]);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
