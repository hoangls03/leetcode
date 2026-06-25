class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            int countTarget = 0;
            for ( int j = i ; j < n ; ++j ) {
                countTarget += (target == nums[j]);
                if ( countTarget > (j - i + 1)/2 ) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
