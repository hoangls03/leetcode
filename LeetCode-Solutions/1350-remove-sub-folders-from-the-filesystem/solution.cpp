class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        map<string,int> mp;
        for ( auto i : folder ) {
            mp[i]++;
        }
        vector<string> ans;
        for ( auto s : folder ) {
            string t = "";
            for ( int i = 0 ; i < s.size() ; ++i ) {
                if ( s[i] == '/' ) {
                    if ( mp[t] != 0 ) {
                        break;
                    } 
                }
                t += s[i];
                if ( i == s.size() - 1 ) {
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};
