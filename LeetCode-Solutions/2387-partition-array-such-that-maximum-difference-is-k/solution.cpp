class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 1;
        int minNum = nums[0];
        for ( int i = 1 ; i < n ; ++i ) {
            if ( abs(nums[i] - minNum) > k ) {
                ans++;
                minNum = nums[i];
            }
            minNum = min(minNum,nums[i]);
        }
        return ans;
    }
};
