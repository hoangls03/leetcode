class Solution {
public:
    int answer( int m, vector<vector<int>>& f, vector<int>& count, int& pos) {
        int l = 0;
        int r = m;
        int ans;
        while ( l <= r ) {
            int mid = ( l + r ) >> 1;
            bool ok = false;
            for ( int i = 1 ; i <= m - mid && !ok ; ++i ) {
                bool check = true;
                for ( int j = 'A' ; j <= 'Z' && check; ++j ) {
                    if ( f[i+mid][j] - f[i-1][j] < count[j] ) check =false;
                }
                for ( int j = 'a' ; j <= 'z' && check; ++j ) {
                    if ( f[i+mid][j] - f[i-1][j] < count[j] ) check =false;
                }
                ok = check;
                if ( ok ) pos = i;
            }
            if ( ok ) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<int> count(150,0);
        for ( int i = 0 ; i < n ; ++i ) {
            count[t[i]]++;
        }
        vector<vector<int>> f(m+1,vector<int>(150,0));
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 'A' ; j <= 'Z' ; ++j ) {
                if ( j == s[i] ) f[i+1][j] = ( i == 0 ) ? 1 : f[i][j] + 1;
                else f[i+1][j] = ( i == 0 ) ? 0 : f[i][j];
            }
            for ( int j = 'a' ; j <= 'z' ; ++j ) {
                if ( j == s[i] ) f[i+1][j] = ( i == 0 ) ? 1 : f[i][j] + 1;
                else f[i+1][j] = ( i == 0 ) ? 0 : f[i][j];
            }
        }
        int pos = -1;
        int temp = answer(m,f,count,pos);
        //cout<<temp<<" "<<pos<<'\n';
        string ans = "";
        if ( pos != -1 ) {
            for ( int i = pos-1 ; i < pos + temp ; ++i ) {
                ans += s[i];
            }
        }
        return ans;
    }
};
