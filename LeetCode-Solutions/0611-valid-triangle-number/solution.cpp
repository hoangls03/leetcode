class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0;
        for ( int i = 1 ; i < n ; ++i ) {
            int pos = 0;
            for ( int j = i + 1 ; j < n ; ++j ) {
                while ( pos < i && nums[j] - nums[i] >= nums[pos] ) {
                    pos++;
                }
                if ( pos < i && nums[i] + nums[pos] > nums[j] ) {
                    ans += i - pos;
                }
            }
        }
        return ans;
    }
};
