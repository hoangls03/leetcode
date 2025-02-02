class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        for ( int i = 0 ; i < n ; ++i ) {
            nums.push_back(nums[i]);
        }
        int ans = 1;
        for ( int i = 1 ; i < 2*n ; ++i ) {
            if ( nums[i] >= nums[i-1] ) {
                ans++;
            } else {
                ans = 1;
            }
            if ( ans >= n ) return true;
        }
        if ( ans == n ) return true;
        return false;
    }
};
