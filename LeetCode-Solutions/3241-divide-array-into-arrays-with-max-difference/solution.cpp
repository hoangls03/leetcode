class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> empty;
        vector<vector<int>> ans(n/3);
        for ( int i = 0 ; i < n-2 ; i += 3 ) {
            if ( nums[i+2] - nums[i] > k ) {
                return empty;
            }
        }
        for ( int i = 0 ; i < n ; ++i ) {
            ans[i/3].push_back(nums[i]);
        }
        return ans;
    }
};
