class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<string> s;
        int wordLen = 0;
        for ( auto word : words ) {
            int n = s.size();
            int len = wordLen + n + word.size();
            if ( len > maxWidth ) {
                int space = maxWidth - wordLen;
                int each = n - 1 == 0 ? 0 : space/(n - 1);
                int left = space - each*(n-1);
                string tmp = "";
                for ( int i = 0 ; i < n ; ++i ) {
                    tmp += s[i];
                    if ( i != n - 1 ) {
                        for ( int j = 0 ; j < each ; ++j ) {
                            tmp += " ";
                        }
                    }
                    if ( left ) {
                        tmp += " ";
                        left--;
                    }
                }
                while ( left > 0 ) {
                    tmp += " ";
                    left--;
                }
                s = {};
                s.push_back(word);
                wordLen = word.size();
                ans.push_back(tmp);
            } else {
                s.push_back(word);
                wordLen += word.size();
            }
        }
        int n = s.size();
        int space = maxWidth - wordLen;
        string tmp = "";
        for ( int i = 0 ; i < n ; ++i ) {
            tmp += s[i];
            if ( space > 0 ) {
                tmp += " ";
                space--;
            }
        }
        while ( space > 0 ) {
            tmp += " ";
            space--;
        }
        ans.push_back(tmp);
        return ans;
    }
};
