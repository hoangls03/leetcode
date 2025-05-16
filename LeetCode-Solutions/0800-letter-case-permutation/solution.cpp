class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        int n = s.size();
        string tmp = "";
        ans.push_back(tmp);
        for ( int i = 0 ; i < n ; ++i ) {
            long long m = ans.size();
            for ( int j = 0 ; j < m ; ++j ) {
                if ( !('0' <= s[i] && s[i] <= '9') ) {
                    string t = ans[j];
                    if ( 'a' <= s[i] && s[i] <= 'z' ) {
                        t += s[i] + ('A' - 'a');
                    } else if ( 'A' <= s[i] && s[i] <= 'Z' ) {
                        t += s[i] + ('a' - 'A');
                    }
                    ans.push_back(t);
                }
                ans[j] += s[i];
            }
        }
        return ans;
    }
};
