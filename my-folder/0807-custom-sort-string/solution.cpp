class Solution {
public:
    string customSortString(string order, string s) {
        int n = s.size();
        vector<int> count(30,0);
        for  ( auto i : s ) {
            count[i-'a']++;
        }
        string ans = "";
        for ( auto i : order ) {
            while ( count[i-'a'] > 0 ) {
                ans += i;
                count[i-'a']--;
            }
        }
        for ( int i = 'a' ; i <= 'z' ; ++i ) {
            while ( count[i-'a'] > 0 ) {
                ans += i;
                count[i-'a']--;
            }
        }
        return ans;
    }
};
