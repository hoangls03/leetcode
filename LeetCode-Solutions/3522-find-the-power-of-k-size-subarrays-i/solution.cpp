class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> b(n,0);
        b[0] = 1;
        for ( int i = 1 ; i < n ; ++i ) {
            b[i] = ( nums[i] == nums[i-1]  + 1);
        }
        vector<int> sum(n,0);
        for ( int i = 0 ;  i < n ; ++i ) {
            sum[i] = i == 0 ? b[i] : sum[i-1] + b[i];
        }
        vector<int> ans;
        for ( int i = 0 ; i < n - k + 1 ; ++i ) {
            if ( sum[i+k-1] - sum[i] == k - 1 ) {
                ans.push_back(nums[i+k-1]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
