class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> mp;
        int ans = 0, sum = 0;
        mp[0] = 1;
        for ( auto i : nums ) {
            sum += i;
            int temp = sum%k;
            if ( temp < 0 ) temp = k + temp;
            ans += mp[temp];
            mp[temp]++;
        }
        return ans;
    }
};
