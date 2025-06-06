class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<int> count('z' + 1,0);
        for ( auto i : s ) {
            count[i]++;
        }
        int ch = 'a';
        string ans = "";
        stack<int> st;
        for ( int i = 0 ; i < n ; ++i ) {
            while ( ch < 'z' && count[ch] == 0 ) {
                ch++;
            }
            while ( st.size() && st.top() <= ch ) {
                ans += st.top();
                st.pop();
            }
            if ( s[i] == ch ) {
                ans += s[i];
            } else {
                st.push(s[i]);
            }
            count[s[i]]--;
        }
        while ( st.size() ) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
