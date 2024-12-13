#define ii pair<int,int>
#define fi first
#define se second
class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<ii> a;
        for ( int i = 0 ; i < nums.size() ; ++i ) {
            a.push_back({nums[i],i});
        }
        sort(a.begin(),a.end());
        int n = nums.size();
        long long ans = 0;
        vector<int> mark(n,0);
        for ( int i = 0 ; i < n ; ++i ) {
            if ( mark[a[i].se] == 0 ) {
                ans += a[i].fi;
                if ( a[i].se - 1 >= 0 ) mark[a[i].se-1] = 1;
                if ( a[i].se + 1 < n ) mark[a[i].se + 1] = 1;
            }
        }
        return ans;
    }
};
