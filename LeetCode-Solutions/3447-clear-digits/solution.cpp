class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        vector<int> mark(n,0);
        stack<int> st;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( 'a' <= s[i] && s[i] <= 'z' ) {
                st.push(i);
            } else {
                if ( st.size() ) {
                    mark[st.top()] = 1;
                    st.pop();
                }
            }
        }
        string ans = "";
        for ( int i = 0 ; i < n ; ++i ) {
            if ( 'a' <= s[i] && s[i] <= 'z' && mark[i] == 0) {
                ans += s[i];
            } 
        }
        return ans;
    }
};
