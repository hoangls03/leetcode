class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<map<long long,int>> f(n);
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 0 ; j < i ; ++j ) {
                long long temp = 1LL*nums[i]-nums[j];
                ans += f[j][temp];
                f[i][temp] += f[j][temp] + 1;
            }
        }
        return ans;
    }
};
