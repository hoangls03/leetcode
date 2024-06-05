class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        vector<int> count(26,0),check(26,0);
        for ( auto i : words[0] ) {
            count[i-'a']++;
        }
        for ( int i = 1 ; i < words.size() ; ++i ) {
            for ( int j = 0 ; j < 26 ; ++j ) {
                check[j] = 0;
            }
            for ( auto j : words[i] ) {
                check[j-'a']++;
            }
            for ( int j = 0 ; j < 26 ; ++j ) {
                count[j] = min(count[j],check[j]);
            }
        }
        for ( int i = 0 ; i < 26 ; ++i ) {
            while ( count[i] > 0 ) {
                char ch = i + 'a';
                string s = "";
                s += ch;
                ans.push_back(s);
                count[i]--;
            }
        }
        return ans;
    }
};
