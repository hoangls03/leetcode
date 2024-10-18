class Solution {
public:
    void write(int n, vector<int>& bt, vector<int>& nums, int& val, int& ans ) {
        int tmp = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( bt[i] ) {
                tmp |= nums[i];
            }
        }
        ans += ( tmp == val );
    }
    void bk(int i, int n, vector<int>& bt, vector<int>& nums, int& val, int& ans ) {
        for ( int j = 0 ; j <= 1 ; ++j ) {
            bt[i] = j;
            if ( i >= n ) break;
            if ( i == n - 1 ) write(n,bt,nums,val,ans);
            else bk(i+1,n,bt,nums,val,ans);
        }
    }
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> bt(20,0);
        int val = 0;
        for ( auto i : nums ) {
            val |= i;
        }
        int ans = 0;
        int n = nums.size();
        bk(0,n,bt,nums,val,ans);
        return ans;
    }
};
