class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>> vt('z' + 1);
        int n = s.size();
        vector<int> mark(n,0);
        for ( int i = 0 ; i < n ; ++i ) {
            if ( s[i] == '*' ) {
                for ( int j = 'a' ; j <= 'z' ; ++j ) {
                    if ( vt[j].size() ) {
                        int index = vt[j][vt[j].size() - 1];
                        mark[index] = 1;
                        vt[j].pop_back(); 
                        break;
                    }
                }
            }
            else vt[s[i]].push_back(i);
        }
        string ans = "";
        for ( int i = 0 ; i < n ; ++i ) {
            if ( mark[i] == 0 && s[i] != '*' ) {
                ans += s[i];
            }
        }
        return ans;
    }
};
