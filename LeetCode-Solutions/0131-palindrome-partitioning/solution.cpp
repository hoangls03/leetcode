class Solution {
public:
    void write(int n, string& s, vector<int>& bt, vector<vector<string>>& ans ) {
        int temp = 0;
        bool check = true;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( bt[i] == 1 ) {
                
                int pos = i;
                for ( int j = temp ; j <= i ; ++j ) {
                    if ( j <= pos ) {
                        if ( s[j] != s[pos] ) {
                            check = false;
                            break;
                        }

                    }
                    pos--;
                }
                temp = i + 1;
            }
        }
        int pos = n - 1;
        for ( int j = temp ; j <= n - 1 ; ++j ) {
            if ( j <= pos ) {
                if ( s[j] != s[pos] ) {
                    check = false;
                }

            }
            pos--;
        }
        if ( n == 3 && bt[0] == bt[1] && bt[0] == 0 ) cout<<check<<'\n';
        if ( check ) {
            string t = "";
            vector<string> vt;
            for ( int i = 0 ; i < n ; ++i ) {
                t += s[i];
                if ( bt[i] == 1 || i == n - 1) {
                    vt.push_back(t);
                    t = "";
                }
            }
            ans.push_back(vt);
        }
       
    }
    void bk(int i, string& s, int n, vector<int>& bt, vector<vector<string>>& ans ) {
        for ( int j = 0 ; j <= 1 ; ++j ) {
            bt[i] = j;
            if ( i == n - 2 ) write(n,s,bt,ans);
            else if ( i < n -2 ) bk(i+1,s,n,bt,ans);
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<int> bt(n,0);
        vector<vector<string>> ans;
        bk(0,s,n,bt,ans);
        if ( n == 1 ) {
            vector<string> temp;
            temp.push_back(s);
            ans.push_back(temp);
        }
        return ans;
    }
};
