class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> mark('z' + 1);
        for ( auto i : brokenLetters ) {
            mark[i] = true;
        }
        int ans = 0;
        vector<string> textList;
        string s = "";
        for ( auto i : text ) {
            if ( i == ' ' ) {
                textList.push_back(s);
                s = "";
            } else {
                s += i;
            }
        }
        textList.push_back(s);
        for ( auto s : textList ) {
            bool ok = true;
            for ( auto i : s ) {
                if ( mark[i] ) {
                    ok = false;
                    break;
                }
            }
            ans += ok;
        }
        return ans;
    }
};
