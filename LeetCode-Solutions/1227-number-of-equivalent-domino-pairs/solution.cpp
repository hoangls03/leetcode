class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for ( auto& i : dominoes ) {
            if ( i[0] > i[1] ) swap(i[0],i[1]);
        }
        int ans = 0;
        map<vector<int>,int> mp;
        for ( auto i : dominoes ) {
            ans += mp[i];
            mp[i]++;
        }
        return ans;
    }
};
