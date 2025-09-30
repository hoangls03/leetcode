class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for ( int i = 0 ; i < n - 1; ++i ) {
            vector<int> tmp;
            for ( int j = 1 ; j < nums.size() ; ++j ) {
                tmp.push_back((nums[j] + nums[j - 1])%10);
            }
            nums = tmp;
        }
        return nums[0];
    }
};
