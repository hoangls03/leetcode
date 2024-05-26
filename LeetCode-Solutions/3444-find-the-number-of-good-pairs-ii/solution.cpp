class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        unordered_map<long long,long long> mp;
        long long ans = 0;
        for ( auto i : nums2 ) {
            i = i*k;
            mp[i]++;
        }
        for ( auto i : nums1 ) {
            for ( int j = 1 ; j <= sqrt(i) ; ++j ) {
                if ( i % j == 0 ) {
                    ans += mp[j];
                    if ( j*j != i ) ans += mp[i/j];
                }
            }
        }
        return ans;
    }
};
