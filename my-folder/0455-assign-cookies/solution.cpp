class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int pos = 0,ans = 0;
        for ( auto i : g ) {
            while ( pos < s.size() && s[pos] < i ) {
                pos++;
            }
            if ( pos >= s.size() ) {
                break;
            }
            if ( pos < s.size() && s[pos] >= i ) {
                pos++;
                ans++;
            }
        }
        return ans;
    }
};
