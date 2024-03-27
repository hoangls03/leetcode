class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int length = nums.size();
        int right_bound = -1;
        int product = 1;
        for ( int i = 0 ; i < length ; ++i ) {
            while ( right_bound+1 < length && product*nums[right_bound+1] < k) {
                product *= nums[right_bound+1];
                right_bound++;
            }
            
            //cout<<i<<" "<<right_bound<<" "<<product<<'\n';
            if ( right_bound >= i ) {
                product /= nums[i];
                ans += right_bound - i + 1;
            }
            if ( right_bound < i ) {
                right_bound = i;
            }
        }
        return ans;
    }
};
