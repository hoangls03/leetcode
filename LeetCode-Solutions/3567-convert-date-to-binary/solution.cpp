class Solution {
public:
    string binacon( long long n ) {
        int mark[30];
        for ( int i = 0 ; i < 30 ; ++i ) {
            mark[i] = 0;
        }
        while ( n > 0 ) {
            int temp = log2(n);
            mark[temp] = 1;
            n -= pow(2,temp);
        }
        bool check = false;
        string ans = "";
        for ( int i = 29 ; i >= 0 ; --i ) {
            if ( mark[i] == 1 ) {
                check = true;
            }
            if ( check ) {
                ans += to_string(mark[i]);
            }
        }
        return ans;
    }
    string convertDateToBinary(string date) {
        long long temp = 0;
        string ans = "";
        for ( auto i : date ) {
            if ( i != '-' ) temp = temp*10 + i - '0';
            if ( i == '-' ) {
                ans += binacon(temp);
                ans += '-';
                temp = 0;
            }
        }
        ans += binacon(temp);
        return ans;
    }
};
