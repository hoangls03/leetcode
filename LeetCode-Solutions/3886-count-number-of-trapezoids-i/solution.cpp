const int oo = 1e9 + 7;
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        map<int,int> mp;
        vector<int> vt;
        for ( auto point : points ) {
            if ( mp[point[1]] == 0 ) {
                vt.push_back(point[1]);
                
            } 
            mp[point[1]]++;
        }
        long long ans = 0,res = 0;
        for ( auto i : vt ) {
            long long m = 1LL*mp[i]*(mp[i] - 1)/2;
            ans += res*m%oo;
            ans %= oo;
            res += m;
            res %= oo;
        }
        return ans;
    }
};
