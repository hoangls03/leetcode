#define ii pair<long long,long long> 
#define fi first
#define se second
class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        vector<ii> a;
        for ( auto i : horizontalCut ) {
            a.push_back({i,0});
        }
        for ( auto i : verticalCut ) {
            a.push_back({i,1});
        }
        sort(a.begin(),a.end());
        int hor = 1;
        int ver = 1;
        long long ans = 0;
        for ( int i = a.size() - 1 ; i >= 0 ; --i ) {
            if ( a[i].se == 0 ) {
                ans += ver*a[i].fi;
                hor++;
            } else {
                ans += hor*a[i].fi;
                ver++;
            }
        }
        return ans;
    }
};
