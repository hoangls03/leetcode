const int dx[] = {100,75,50,25};
const int dy[] = {0,25,50,75};
class Solution {
public:

    double cal( int A, int B, vector<vector<double>>& dp ) {
        if ( A == 0 && B == 0 ) {
            return 0.5;
        }
        if ( A == 0 ) {
            return 1;
        }
        if ( B == 0 ) {
            return 0;
        } 
        if ( dp[A][B] != -1 ) {
            return dp[A][B];
        }
        double res = 0;
        for ( int i = 0 ; i < 4 ; ++i ) {
            int sA = max(A - dx[i],0);
            int sB = max(B - dy[i],0);
            res += cal(sA,sB,dp);
        }
        dp[A][B] = res/4;
        return dp[A][B];
    }
    double soupServings(int n) {
        if ( n >= 5000 ) return 1.0;
        vector<vector<double>> dp(5000,vector<double>(5000,-1));
        return cal(n,n,dp);
    }
};
