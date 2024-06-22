class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        vector<int> count(n+1,0);
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            ( nums[i] & 1 ) ? nums[i] = 1 : nums[i] = 0;
        }
        count[0] = 1;
        for ( int i = 0 ; i < n ; ++i ) {
            sum += nums[i];
            count[sum]++;
            if ( sum >= k ) {
                ans += count[sum-k];
            }
            
        }
        return ans;
    }
};
