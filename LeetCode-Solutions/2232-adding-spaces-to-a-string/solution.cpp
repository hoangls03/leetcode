class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        reverse(spaces.begin(),spaces.end());
        for ( int i = 0 ; i < s.size() ; ++i ) {
            if ( spaces.size() && i == spaces.back() ) {
                ans += " ";
                spaces.pop_back();
            }
            ans += s[i];
        }
        return ans;
    }
};
