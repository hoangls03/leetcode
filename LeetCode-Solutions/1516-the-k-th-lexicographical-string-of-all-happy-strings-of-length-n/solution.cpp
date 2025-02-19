class Solution {
public:
    void write( int n, vector<int>& bt, string& ans, int& count) {
        if ( count == 0 ) return ;
        bool check = true;
        for ( int i = 0 ; i < n - 1 && check ; ++i ) {
            if ( bt[i] == bt[i+1] ) check = false;
        }
        if ( check ) {
            count -= check;
            if ( count == 0 ) {
                for ( int i = 0 ; i < n ; ++i ) {
                    ans += 'a' + bt[i];
                }
            }
        }
    }
    void bk( int i, int n, vector<int>& bt, string& ans, int& count) {
        for( int j = 0 ; j < 3 ; ++j ) {
            bt[i] = j;
            if ( i == n - 1 ) write(n,bt,ans,count);
            else if ( i >= n ) break;
            else bk(i+1,n,bt,ans,count);
        }
    }
    string getHappyString(int n, int k) {
        string ans = "";
        vector<int> bt(n);
        bk(0,n,bt,ans,k);
        return ans;
    }
};
