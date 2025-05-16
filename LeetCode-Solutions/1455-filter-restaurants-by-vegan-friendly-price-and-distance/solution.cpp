#define ii pair<int,int>
#define fi first
#define se second
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<ii> res;
        vector<int> ans;
        veganFriendly = 1 - veganFriendly;
        for ( auto i : restaurants ) {
            if ( (i[2] | veganFriendly) && (i[3] <= maxPrice) && (i[4] <= maxDistance) ) {
                res.push_back({i[1],i[0]});
            }
        }
        sort(res.begin(),res.end(),greater<ii>());
        for ( auto i : res ) {
            ans.push_back(i.se);
        }
        return ans;
    }
};
