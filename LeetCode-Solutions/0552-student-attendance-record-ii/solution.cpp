const int oo = 1e9 + 7;
class Solution {
public:
    int Record( int index, int count_a, int count_l, int n, vector<vector<vector<int>>>& dp ) {
        if ( index == n ) {
            return 1;
        }
        if ( dp[index][count_a][count_l] != - 1 ) return dp[index][count_a][count_l];
        int get_A = count_a == 1 ? 0 : Record(index+1,count_a+1,0,n,dp);
        int get_L = count_l == 2 ? 0 : Record(index+1,count_a,count_l+1,n,dp);
        int get_P = Record(index+1,count_a,0,n,dp);
        int get_next = ((get_A + get_L)%oo + get_P)%oo;
        dp[index][count_a][count_l] = get_next;
        return get_next;
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        int ans = Record(0,0,0,n,dp);
        return ans;
    }
};
