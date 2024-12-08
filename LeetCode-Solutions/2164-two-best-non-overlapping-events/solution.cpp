class Solution {
public:
    static bool cmp (vector<int>& a, vector<int>& b) {
        if ( a[1] == b[1] ) {
            if ( a[0] == b[0] ) return a[2] < b[2];
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(),events.end(),cmp);
        vector<int> localMax(n,0);
        for ( int i = 0  ; i < n ; ++i ) {
            localMax[i] = i == 0 ? events[i][2] : max(localMax[i-1],events[i][2]);
        }
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            int l = 0;
            int r = n - 1;
            ans = max(ans,events[i][2]);
            while ( l <= r ) {
                int mid = ( l + r ) >> 1;
                if ( events[mid][1] < events[i][0] ) {
                    l = mid + 1;
                    ans = max(ans,events[i][2] + localMax[mid]);
                } else {
                    r = mid - 1;
                }
            }
        }
        return ans;
    }
};
