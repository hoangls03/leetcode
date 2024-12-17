class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.size();
        vector<int> mark(26,0);
        for ( int i = 0 ; i < n ; ++i ) {
            mark[s[i]-'a']++;
        }
        string ans = "";
        vector<int> cons(26,0);
        bool check = true;
        while ( check ) {
            for ( int i = 'z' ; i >= 'a' ; --i ) {
                if ( cons[i-'a'] < repeatLimit && mark[i-'a'] > 0 ) {
                    mark[i-'a']--;
                    cons[i-'a']++;
                    if ( ans.size() && ans[ans.size()-1] != i ) {
                        cons[ans[ans.size()-1] - 'a'] = 0;
                    }
                    ans+= i;
                    break;
                } else if ( i == 'a' ) {
                    check = false;
                }
            }

        }
        return ans;
    }
};
