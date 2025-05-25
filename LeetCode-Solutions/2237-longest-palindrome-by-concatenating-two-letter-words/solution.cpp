class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        map<string,int> mp;
        for ( auto s : words ) {
            string t = s;
            reverse(t.begin(),t.end());
            if ( mp[t] > 0 ) {
                ans += 4;
                mp[t]--;
            } else mp[s]++;
        } 
        for ( auto s : words ) {
            if ( mp[s] > 0 && s[0] == s[1] ) {
                ans += 2;
                break;
            }
        }
        return ans;
    }
};
