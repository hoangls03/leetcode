class Solution {
public:
    bool isPathCrossing(string path) {
        bool ans = false;
        int n = path.size();
        path = " " + path;
        vector<int> dem(path.size(),0),dem1(path.size(),0);
        for ( int i = 1 ; i <= n && !ans; ++i ) {
            if ( path[i] == 'N' && path[i-1] == 'S' ) ans = true;
            if ( path[i] == 'S' && path[i-1] == 'N' ) ans = true;
            if ( path[i] == 'E' && path[i-1] == 'W' ) ans = true;
            if ( path[i] == 'W' && path[i-1] == 'E' ) ans = true;
        }
        for ( int i = 1 ; i <= n ; ++i ) {
            if ( path[i] == 'N' ) {
                dem[i] = dem[i-1] + 1;
                dem1[i] = dem1[i-1];
            }
            if ( path[i] == 'S' ) {
                dem[i] = dem[i-1] - 1;
                dem1[i] = dem1[i-1];
            }
            if ( path[i] == 'W' ) {
                dem1[i] = dem1[i-1] + 1;
                dem[i] = dem[i-1];
            }
            if ( path[i] == 'E' ) {
                dem1[i] = dem1[i-1] - 1;
                dem[i] = dem[i-1];
            }
        }
        for ( int i = 1 ; i <= n&& !ans; ++i ) {
            for ( int j = 1 ; i+j <= n && !ans; ++j ) {
                if (( (dem[i+j] - dem[i-1]) == 0) && ((dem1[i+j] - dem1[i-1]) == 0) ) {
                  ans = true;
              }
            }
        }
        return ans;
    }
};
