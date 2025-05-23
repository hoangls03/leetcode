class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mark(n + 1,1);
        for ( int i = n - 2 ; i >= 0 ; --i ) {
            if ( nums[i] <= nums[i+1] ) {
                mark[i] = mark[i+1] + 1;
            }
        }
        int count = 0;
        vector<int> ans;
        mark[n] = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( count >= k && mark[i+1] >= k ) {
                ans.push_back(i);
            }
            if ( i == 0 || nums[i] > nums[i-1] ) {
                count = 1; 
            } else {
                count++;
            }
        }
        return ans;
    }
};
