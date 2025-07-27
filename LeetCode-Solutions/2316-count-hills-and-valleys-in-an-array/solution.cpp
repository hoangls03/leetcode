class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for ( int i = 1 ; i < n ; ++i ) {
            if ( nums[i] != nums[i-1] ) {
                int leftVal = 0; 
                for ( int j = i - 1 ; j >= 0 ; --j ) {
                    if ( nums[j] != nums[i] ) {
                        leftVal = nums[i] - nums[j];
                        break;
                    }
                }
                int rightVal = 0;
                for ( int j = i + 1 ; j < n ; ++j ) {
                    if ( nums[j] != nums[i] ) {
                        rightVal = nums[i] - nums[j];
                        break;
                    }
                }
                ans += (leftVal * rightVal > 0);
            }
        }
        return ans;
    }
};
