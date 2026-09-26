class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string> mp;
        for ( auto i : knowledge ) {
            mp[i[0]] = i[1];
        }
        string cur = "",ans = "";
        for ( auto i : s ) {
            if ( i == '(' ) {
                ans += cur;
                cur = "";
            } else if ( i == ')' ) {
                if ( mp[cur] == "" ) {
                    ans += "?";
                } else {
                    ans += mp[cur];
                }
                cur = "";
            } else {
                cur += i;
            }
        }
        ans += cur;
        return ans;
    }
};
