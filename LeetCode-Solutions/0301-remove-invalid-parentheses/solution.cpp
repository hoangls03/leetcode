class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        int minDelete = n;
        vector<string> res;
        map<string,int> mp;
        string ans = "";
        vector<int> pos;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( s[i] == '(' || s[i] == ')' ) {
                pos.push_back(i);
            }
        }
        int m = pos.size();
        vector<int> mark(n,1);
        // cout<<m<<'\n';
        for ( int i = 0 ; i < (1 << m) ; ++i ) {
            bool ok = true;
            int countDelete = 0;
            int countParentheses = 0;
            for ( int j = 0 ; j < m ; ++j ) {
                if ( (i >> j) & 1 ) {
                    int val = pos[j];
                    if ( s[val] == '(' ) {
                        countParentheses++;
                    } 
                    if ( s[val] == ')') {
                        countParentheses--;
                    }
                    if ( countParentheses < 0 ) {
                        ok = false;
                        break;
                    }

                } else {
                    countDelete++;
                }
            }
            if ( countParentheses != 0 ) {
                ok = false;
            }
            if ( ok ) {
                if ( countDelete <= minDelete ) {
                    if ( countDelete < minDelete ) {
                        res.clear();
                    }
                    minDelete = countDelete;
                    ans = "";
                    for ( int j = 0 ; j < m ; ++j ) {
                        int val = pos[j];
                        if ( (i >> j) & 1 ) {
                            mark[val] = 1 ;
                        } else {
                            mark[val] = 0;
                        }
                    }
                    // cout<<i<<'\n';
                    for ( int j = 0 ; j < n ; ++j ) {
                        if ( mark[j] == 1 ) {
                            ans += s[j];
                        }
                    }
                    res.push_back(ans);
                }
            }
        }
        vector<string> uniqueRes;
        for ( auto i : res ) {
            if ( mp[i] == 0 ) {
                uniqueRes.push_back(i);
                mp[i]++;
            }
        }
        return uniqueRes;
    }
};
