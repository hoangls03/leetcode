class Solution {
public:
    void write(vector<int>&nums, vector<int>& bt, int n,vector<vector<int>>& ans) {
        vector<int> temp;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( bt[i] == 0 ) {
                temp.push_back(nums[i]);
            }
        }
        ans.push_back(temp);
    }
    void bk(int i, vector<int>& nums, vector<int>&bt, int n, vector<vector<int>>& ans ) {
        for ( int j = 0 ; j <= 1 ; ++j ) {
            bt[i] = j;
            if ( i == n - 1 ) write(nums,bt,n,ans);
            else bk(i+1,nums,bt,n,ans);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> bt(n);
        bk(0,nums,bt,n,ans);
        return ans;
    }
};
