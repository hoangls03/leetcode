#define ii pair<int,int>
#define fi first 
#define se second
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<ii> pos;
        int n = nums.size();
        for ( int i = 0 ; i < n ; ++i ) {
            pos.push_back({nums[i],i});
        }
        sort(pos.begin(),pos.end());
        int ans = -1e9;
        int local_min = pos[0].se; 
        for ( int i = 1 ; i < n ; ++i ) {
            ans = max(ans,pos[i].se-local_min);
            local_min = min(local_min,pos[i].se);
        }
        if ( ans < 0 ) return 0;
        return ans;
    }
};
