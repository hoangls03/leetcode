class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> mark(n,0),sum(n,0);
        nums[0] %= 2;
        for ( int i = 1 ; i < n ; ++i ) {
            nums[i] %= 2;
            if ( nums[i] != nums[i-1] ) mark[i] = 1; 
        }
        sum[0] = 1;
        for ( int i = 1 ; i < n ; ++i ) {
            sum[i] = sum[i-1] + mark[i];
        }
        vector<bool> ans;
        for ( auto e : queries ) {
            if ( sum[e[1]] - sum[e[0]] == e[1] - e[0] ) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};
