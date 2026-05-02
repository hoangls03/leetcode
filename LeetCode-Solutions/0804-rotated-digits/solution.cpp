class Solution {
public:
    bool check(int n, vector<int>& mark) {
        bool ok = false;
        while ( n > 0 ) {
            if ( mark[n%10] == -1 ) {
                return false;
            }
            if ( mark[n%10] != n%10 ) {
                ok = true;
            }
            n /= 10;
        }
        return ok;
    }
    int rotatedDigits(int n) {
        int ans = 0;
        vector<int> mark(10,-1);
        mark[0] = 0;
        mark[1] = 1;
        mark[8] = 8;
        mark[2] = 5;
        mark[5] = 2;
        mark[6] = 9;
        mark[9] = 6;
        for ( int i = 1 ; i <= n ; ++i ) {
            ans += check(i,mark);
        }
        return ans;
    }
};
