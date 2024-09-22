class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        map<string,int> mp;
        for ( auto s : bannedWords ) {
            mp[s] = 1;
        }
        int ans = 0;
        for ( auto s : message ) {
            ans += mp[s];
        }
        if ( ans >= 2 ) {
            return true;
        }
        return false;
    }
};
