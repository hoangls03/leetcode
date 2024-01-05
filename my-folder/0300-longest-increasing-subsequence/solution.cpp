class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n,1);
        int ans = 1;
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = i + 1 ; j < n ; ++j ) {
                if ( nums[j] > nums[i] ) {
                    //cout<<i<<" "<<j<<" "'\n';
                    f[j] = max(f[j],f[i]+1);
                }
            }
        }
        for ( auto i : f ) {
            ans = max(ans,i);
        }
        return ans;
    }
};
