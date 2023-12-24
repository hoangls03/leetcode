class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> vt(points.size());
        for ( int i = 0 ; i < points.size() ; ++i ) {
            vt[i] = points[i][0];
        }
        sort(vt.begin(),vt.end());
        int ans;
        for ( int i = 1 ; i < vt.size() ; ++i ) {
            ans = max(ans,vt[i]-vt[i-1]);
        }
        return ans;
    }
};
