class Solution {
public:
    bool checkAnagrams( string s, string t ) {
        if ( s.size() != t.size() ) return false;
        vector<int> mark('z' + 1);
        for ( auto i : t ) {
            mark[i]++;
        }
        for ( auto i : s ) {
            mark[i]--;
        }
        for ( int i = 'a' ; i <= 'z' ; ++i ) {
            if ( mark[i] != 0 ) return false;
        }
        return true;

    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        for ( auto i : words ) {
            if ( ans.size() == 0 ) {
                ans.push_back(i);
            } else {
                if ( !checkAnagrams(ans[ans.size() -1],i) ) {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};
