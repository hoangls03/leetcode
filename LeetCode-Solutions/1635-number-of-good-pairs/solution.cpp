class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0; // the answer to the problem
        int n = nums.size();
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = i + 1 ; j < n ; ++j ) {
                if ( nums[j] == nums[i] ) ans++;
            }
        }
        return ans;
    }
};
