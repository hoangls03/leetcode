class Solution {
public:
    long long wonderfulSubstrings(string word) {
        map<long long,int> mp;
        long long ans = 0;
        int bit = 0;
        mp[0] = 1;
        for ( auto ch : word ) {
            int pos = ch - 'a';
            bit ^= ( 1 << pos );
            ans += mp[bit];
            for ( int i = 0 ; i <= 'j' - 'a' ; ++i ) {
                ans += mp[bit^(1<<i)];
            }
            mp[bit]++;
        }
        return ans;
    }
};
