class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> st;
        vector<bool> check(n+1,false);
        for ( int i = 0 ; i < n ; ++i ) {
            char ch = s[i];
            if ( ch == '(' ) {
                st.push(i);
            } 
            if ( ch == ')' ) {
                if ( !st.empty() ) {
                    int pos = st.top();
                    if ( s[pos] == '(' ) {
                        check[pos] = true;
                        check[i] = true;
                        st.pop();
                    }
                }
            }
        }
        string ans = "";
        for ( int i = 0 ; i < s.size() ; ++i ) {
            if ( (s[i] != '(' && s[i] != ')') || check[i] ) {
                ans += s[i];
            } 
        }
        return ans;
    }
};
