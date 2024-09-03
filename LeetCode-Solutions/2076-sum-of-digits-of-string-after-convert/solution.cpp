class Solution {
public:
    int getLucky(string s, int k) {
        int n = s.size();
        string temp = "";
        for ( int i = 0 ; i < n ; ++i ) {
            temp += to_string(s[i]-'a'+1);
        }
        int ans = 0;
        while ( k ) {
            ans = 0;
            for ( int i = 0 ; i < temp.size() ; ++i ) {
                ans += temp[i] - '0';
            }
            temp = to_string(ans);
            k--;
        }
        return ans;
    }
};
