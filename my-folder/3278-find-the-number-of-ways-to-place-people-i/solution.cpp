class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( points[i][0] <= points[j][0] && points[i][1] >= points[j][1] && i != j) {
                    //cout<<i<<" "<<j<<'\n';
                    bool check = true;
                    for ( int k = 0 ; k < n ; ++k ) {
                        if ( k != i && k != j && points[k][0] >= points[i][0] && points[k][0] <= points[j][0] &&
                                                 points[k][1] >= points[j][1] && points[k][1] <= points[i][1]) check = false;
                    }
                    ans += check;
                }
            }
        }
        //cout<<"debug"<<'\n';
        return ans;
    }
};
