class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = i + 1 ; j < n ; ++j ) {
                for ( int k = j + 1 ; k < n ; ++k ) {
                    if ( nums[i] == nums[j] && nums[j] == nums[k] ) {
                        int val = j - i + k - j + k - i;
                        if ( ans == -1 ) {
                            ans = val;
                        } else {
                            ans = min(ans,val);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
