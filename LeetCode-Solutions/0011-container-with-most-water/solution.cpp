#define ii pair<int,int>
#define fi first
#define se second
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        vector<ii> height_pos;
        for ( int i = 0 ; i < n ; ++i ) {
            height_pos.push_back({height[i],i});
        }
        sort(height_pos.begin(),height_pos.end());
        int max_pos = -1;
        int min_pos = n + 1;
        int ans = 0;
        for ( int i = n - 1 ; i >= 0 ; --i ) {
            if ( max_pos != -1 ) {
                int temp = max(abs(max_pos-height_pos[i].se),abs(height_pos[i].se-min_pos));
                ans = max(ans,temp*height_pos[i].fi);
            }
            max_pos = max(max_pos,height_pos[i].se);
            min_pos = min(min_pos,height_pos[i].se);
        }
        return ans;
    }
};
