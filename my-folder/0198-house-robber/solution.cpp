class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n,0);
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            f[i] = nums[i];
        }
        for ( int  i = 1 ; i < n ; ++i ) {
            for ( int j = 0 ; j >= 0 && j < i - 1 ; ++j ) {
                f[i] = max(f[i],f[j] + nums[i]);
            }
        }
        for ( int i = 0 ; i < n ; ++i ) {
            cout<<f[i]<<" ";
            ans = max(ans,f[i]);
        }
        return ans;
    }
};
