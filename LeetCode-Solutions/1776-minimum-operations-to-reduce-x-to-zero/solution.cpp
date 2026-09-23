class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        vector<int> nums1;
        int count=2;
        int m = nums.size();
        while (count--) {
            for ( auto i : nums ) {
                nums1.push_back(i);
            }
        }
        map<long long,int> mp;
        int n = nums1.size();
        long long sum = 0;
        int ans = 1e9;
        for ( int i = 0 ; i < n ; ++i ) {
            sum += nums1[i];
            if ( mp[sum - x] > 0 && (mp[sum - x] < m || mp[sum-x] <= m ) && i >= m - 1 ) {
                ans = min(ans,i + 1 - mp[sum-x]);
            }
            mp[sum] = i + 1;
        }
        if ( ans > m ) ans = -1;
        return ans;
    }
};
