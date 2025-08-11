const int oo = 1e9 + 7;
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> nums;
        while ( n > 0 ) {
            int tmp = log2(n);
            nums.push_back(( 1 << tmp));
            n -= (1 << tmp);
        }
        sort(nums.begin(),nums.end());
        int m = nums.size();
        vector<vector<int>> mark(m,vector<int>(m,1));
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = i ; j < m ; ++j ) {
                if ( i == j ) mark[i][j] = nums[i];
                else mark[i][j] = 1LL*mark[i][j-1] * nums[j] % oo;
            }
        }
        vector<int> ans;
        for ( auto i : queries ) {
            ans.push_back(mark[i[0]][i[1]]);
        }
        return ans;
    }
};
