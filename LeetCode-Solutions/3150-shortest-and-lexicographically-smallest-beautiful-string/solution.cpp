class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int n = s.size();
        for ( int i = 0 ; i < n ; ++i ) {
            int count1 = 0;
            string tmp = "";
            for ( int j = i ; j < n ; ++j ) {
                count1 += (s[j] == '1');
                tmp += s[j];
                if ( count1 == k ) {
                    if ( tmp.size() < ans.size() || ans.size() == 0 ) {
                        ans = tmp;
                    } else if ( tmp.size() == ans.size() ) {
                        ans = min(ans,tmp);
                    }
                    break;
                }
            }
        }
        return ans;
    }
};
