class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(26,0);
        for ( auto i : s ) {
            count[i-'a']++;
        }
        int ans = -1;
        for ( int i = 0 ; i < s.size() ; ++i ) {
            if ( count[s[i]-'a'] == 1 ) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
