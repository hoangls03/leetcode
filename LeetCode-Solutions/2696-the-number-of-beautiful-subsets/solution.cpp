class Solution {
public:
    unordered_map<int,int> mp;
    void backtrack( int pos, int n, vector<int>& nums, int k , int& ans) {
        if ( pos == n ) {
            ans++;
            return ;
        }
        if ( mp[nums[pos] - k] == 0 ) {
            mp[nums[pos]]++;
            backtrack(pos+1,n,nums,k,ans);
            mp[nums[pos]]--;
        }
        backtrack(pos+1,n,nums,k,ans);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            mp[nums[i]]++;
            backtrack(i+1,n,nums,k,ans);
            mp[nums[i]]--;
        }
        return ans;
    }
};
