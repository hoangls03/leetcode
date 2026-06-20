class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});
        sort(restrictions.begin(),restrictions.end());
        int m = restrictions.size();
        if ( restrictions[m-1][0] !=  n ) {
            restrictions.push_back({n,n - 1});
            m++;
        }
        vector<int> l(m,0), r(m,0), h(m,0);
        for ( int i = 1 ; i < m ; ++i ) {
            int dis = restrictions[i][0] - restrictions[i - 1][0];
            l[i] = min(l[i-1] + dis, restrictions[i][1]);
        }

        r[m-1] = min(restrictions[m - 1][1], l[m-1]);
        for ( int i = m - 2 ; i >= 0 ; --i ) {
            int dis = restrictions[i + 1][0] - restrictions[i][0];
            r[i] = min(r[i + 1] + dis, restrictions[i][1]);
        }

        for ( int i = 0 ; i < m ; ++i ) {
            h[i] = min(l[i], r[i]);
        }
        int ans = 0;
        for ( int i = 1 ; i < m ; ++i ) {
            ans = max(ans,h[i]);
            int cur = abs(h[i] - h[i-1]) + restrictions[i][0] - restrictions[i - 1][0];
            cur /= 2;
            ans = max(ans, min(h[i],h[i-1]) + cur);
        }
        return ans;
    }
};
