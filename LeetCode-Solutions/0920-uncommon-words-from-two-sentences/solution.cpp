class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int> mark;
        vector<string> ans;
        string s = "";
        for ( auto i : s1 ) {
            if ( i == ' ' ) {
                mark[s]++;
                s = "";
            } else {
                s += i;
            }
        }
        mark[s]++;
        s = "";
        for ( auto i : s2 ) {
            if ( i == ' ' ) {
                mark[s]++;
                s = "";
            } else {
                s += i;
            }
        }
        if ( mark[s] == 0 ) ans.push_back(s);
        mark[s]++;
        s = "";
        for ( auto i : s2 ) {
            if ( i == ' ' ) {
                if ( mark[s] == 1 ) ans.push_back(s);
                s = "";
            } else {
                s += i;
            }
        }
        s = "";
        for ( auto i : s1 ) {
            if ( i == ' ' ) {
                if ( mark[s] == 1 ) {
                    ans.push_back(s);
                }
                s = "";
            } else {
                s += i;
            }
        }
        if ( mark[s] == 1 ) ans.push_back(s);

        return ans;
    }
};
