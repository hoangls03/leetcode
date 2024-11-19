class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int pos = 0;
        map<int,int> mp;
        mp.clear();
        long long ans = 0,sum = 0;
        mp[nums[0]] = 1;
        sum += nums[0];
        for ( int i = 0 ; i < n ; ++i ) {
            while ( pos < n - 1 && pos - i + 1 < k && mp[nums[pos+1]] == 0 ) {
                pos++;
                sum += nums[pos];
                mp[nums[pos]]++;
            }
            if ( pos - i + 1 == k ) {
                ans = max(ans,sum);
            }
            sum -= nums[i];
            mp[nums[i]]--;
        }
        return ans;
    }
};
