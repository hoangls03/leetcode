class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string tmp = "";
        string ans = "";
        for ( auto i : s ) {
            if ( i == ']' ) {
                for ( auto j : tmp ) {
                    st.push(j);
                }
                tmp = "";
                while ( st.size() && !('0' <= st.top() && st.top() <= '9') ) {
                    if ( st.top() != '[' ) tmp = st.top() + tmp;
                    st.pop();
                } 
                string numString = "";
                while ( st.size() && '0' <= st.top() && st.top() <= '9' ) {
                    numString = st.top() + numString;
                    st.pop();
                }
                if ( numString != "" ) {
                    int num = stoi(numString);
                    string duplicate = tmp;
                    for ( int j = 0 ; j < num - 1; ++j ) {
                        tmp += duplicate;
                    }
                }
                for ( auto j : tmp ) {
                        st.push(j);
                }
                tmp = "";
            } else {
                for ( auto j : tmp ) {
                        st.push(j);
                }
                tmp = "";
                st.push(i);
            }
        }
        while ( st.size() ) {
            if ( st.top() != '[' ) ans = st.top() + ans;
            st.pop();
        }
        return ans + tmp;
    }
};
