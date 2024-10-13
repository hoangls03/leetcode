#define ii pair<int,int>
#define fi first
#define se second
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<ii> vt;
        int k = nums.size();
        for ( int i = 0 ; i < nums.size() ; ++i ) {
            auto list = nums[i];
            for ( auto num : list ) {
                vt.push_back({num,i});
            }
        }
        sort(vt.begin(),vt.end());
        int pos = 0;
        int n = vt.size();
        int type = 0;
        vector<int> mark(k,0);
        int len = 1e9;
        vector<int> ans;
        for ( int i = 0 ; i < n ; ++i ) {
            pos = max(pos,i);
            while ( pos < n && type < k ) {
                if ( mark[vt[pos].se] == 0 ) type++;
                mark[vt[pos].se]++;
                pos++;
            }
            if ( type == k ) {
                if ( vt[pos-1].fi - vt[i].fi < len ) {
                    ans = {vt[i].fi,vt[pos-1].fi};
                    len = vt[pos-1].fi - vt[i].fi;
                }
            }
            mark[vt[i].se]--;
            if ( mark[vt[i].se] == 0 ) type--;
        }
        return ans;
    }
};
