class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string> ans;
        string t = "";
        for ( int i = 0 ; i < n ; ++i ) {
            if ( i % k == 0 && i != 0 ) {
                ans.push_back(t);
                t = "";
            }
            t += s[i];
        }
        if ( t.size() != 0 ) {
            while ( t.size() < k ) {
                t += fill;
            }
            ans.push_back(t);
        }
        return ans;
    }
};
