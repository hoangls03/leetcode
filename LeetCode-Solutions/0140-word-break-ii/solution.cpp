class Solution {
public:
    int bt[25];
    map<string,int> mp;
    void write(int n, string& s, vector<string>& ans ) {
        string temp = "";
        bool check = true;
        for ( int i = 1 ; i <= n + 1 && check; ++i ) {
            if ( bt[i] == 0 ) {
                if(mp[temp] == 0 ) {
                    check = false;
                }
                if ( i <= n ) {
                    temp = "";
                    temp += s[i];
                }
            }
            if ( bt[i] == 1 ) {
                temp += s[i];
            }
        }
        temp = "";
        if ( check ) {
            for ( int i = 1 ; i <= n; ++i ) {
                if ( bt[i] == 0 ) {
                    temp += " ";
                }
                temp += s[i];
            }
            ans.push_back(temp);
        } 
    }
    void bk( int i, int n, string& s, vector<string>& ans ) {
        for ( int j = 0 ; j <= 1 ; ++j ) {
            bt[i] = j;
            if ( i == n ) write(n,s,ans);
            else bk(i+1,n,s,ans);
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        s = " " + s;
        memset(bt,0,sizeof(bt));
        for ( auto i : wordDict ) {
            mp[i] = 1;
        }
        vector<string> ans;
        bk(1,n,s,ans);
        mp.clear();
        return ans;
    }
};
