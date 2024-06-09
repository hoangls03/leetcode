class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        map<int,int> mp;
        sort(rewardValues.begin(),rewardValues.end());
        mp[0] = 1;
        int ans = 0;
        for ( auto i : rewardValues ) {
            for ( int j = i - 1 ; j >= 0 ; --j ) {
                if ( mp[j] == 1 ) {
                    mp[j+i] = 1;
                    ans = max(ans,j+i);
                }
            }
        }
        return ans;
    }
};
