class Solution {
public:
    static bool cmp ( vector<int>& a, vector<int>& b ) {
        if ( a[0] == b[0] ) return a[1] < b[1];
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        for ( auto i : points) {
            cout<<i[0]<<" "<<i[1]<<'\n';
        }
        int ans = 1,prev = points[0][1];
        for ( int i = 1 ; i < points.size() ; ++i ) {
            if ( points[i][0] > prev ) {
                prev = points[i][1];
                ans++;
            } else {
                prev = min(prev,points[i][1]);
            }
        }
        return ans;
    }
};
