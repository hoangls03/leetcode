class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans = 0;
        int x = 24;
        map<long long,long long> mp;
        mp.clear();
        for ( int i = 0 ; i < hours.size() ; ++i ) {
            hours[i] = hours[i]%24;
            mp[hours[i] ]++;
        }
        for ( auto i : hours ) {
            if ( i == 12 || i == 0 ) {
                if ( mp[i] > 0 ) ans += mp[i] - 1;
            } else {
                if ( mp[24-i] >= 0 ) ans += mp[24-i];
            }
            mp[i]--;
        }
        return ans;
    }
};
