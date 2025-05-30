class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> mark('z' + 1,-1);
        vector<int> lastOccur('z' + 1,1e4);
        int n = s.size();
        for ( int i = 0 ; i < n ; ++i ) {
            lastOccur[s[i]] = i; 
        }
        int len = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( mark[s[i]] == -1 ) {
                mark[s[i]] = len;
                len++;
            } else {
                bool check = true;
                int pos = len + 1;
                for ( int j = 'a' ; j <= 'z' ; ++j ) {
                    if ( mark[j] != -1 && j < s[i] && mark[j] > mark[s[i]] ) {
                        pos = min(pos,mark[j]);
                    }
                }
                if ( pos == len + 1) {
                    check = false;
                }
                for ( int j = 'a' ; j <= 'z' && check ; ++j ) {
                    if ( j > s[i] && mark[j] != -1 && mark[j] < pos && mark[j] > mark[s[i]] && lastOccur[j] < i ) {
                        check = false;
                    }
                }
                if ( check ) {
                    for ( int j = 'a' ; j <= 'z' ; ++j ) {
                        if ( mark[j] > mark[s[i]] ) {
                            mark[j]--;
                        }
                    }
                    mark[s[i]] = len - 1;
                }
                
            }
        }
        string ans = "";
        for ( int i = 0 ; i < len ; ++i ) {
            ans += "a";
        }
        for ( int i = 'a' ; i <= 'z' ; ++i ) {
            if ( mark[i] != -1 ) {
                ans[mark[i]] = i;
            }
        }
        return ans;
    }
};
