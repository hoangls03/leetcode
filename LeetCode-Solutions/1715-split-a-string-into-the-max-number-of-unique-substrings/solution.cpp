class Solution {
public:
    void write( vector<int>& bt, int& n, string& s, int& ans) {
        string t = "";
        map<string,int> mp;
        bool check = true;
        int count = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            t += s[i];
            if ( bt[i] == 1) {
                count++;
                if ( mp[t] != 0 ) {
                    check = false;
                    break;
                }
                mp[t]++;
                t = "";
            }
        }
        if ( check ) {
            ans = max(ans,count);
        }
    }
    void bk( int i, int& n, vector<int>& bt, string& s, int& ans ) {
        for ( int j = 0 ; j <= 1 ; ++j ) {
            bt[i] = j;
            if ( i > n - 1 ) break;
            if ( i == n - 1 ) write(bt,n,s, ans);
            else bk(i+1,n,bt,s,ans);
        }
    }
    int maxUniqueSplit(string s) {
        int n = s.size();
        vector<int> bt(n+1);
        int ans = 0;
        bk(0,n,bt,s,ans);
        return ans;
    }
};
