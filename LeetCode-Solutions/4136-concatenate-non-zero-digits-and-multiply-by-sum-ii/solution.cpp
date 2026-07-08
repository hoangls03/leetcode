const int oo = 1e9 + 7;
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long> sum(n + 1,0);
        vector<long long> x(n+1,0),mark(n+1,0);
        for ( int i = 1 ; i <= n ; ++i ) {
            int val = s[i-1] - '0';
            sum[i] = sum[i-1] + val;
            x[i] = (val != 0) ? (x[i - 1]*10 + val)%oo : x[i-1];
            mark[i] = (val != 0) ? mark[i-1] + 1 : mark[i-1];
        }
        vector<long long> pow10(n + 1,1);
        for ( int i = 1 ; i <= n ; ++i ) {
            pow10[i] = pow10[i-1]*10%oo;
        }
        vector<int> ans;
        for ( auto q: queries ) {
            int u = q[0] + 1, v = q[1] + 1;
            int len = mark[v] - mark[u-1];
            long long val = (x[v] - x[u-1]*pow10[len]%oo + oo)%oo;
            ans.push_back(val*(sum[v] - sum[u-1])%oo);
        }
        return ans;
    }
};
