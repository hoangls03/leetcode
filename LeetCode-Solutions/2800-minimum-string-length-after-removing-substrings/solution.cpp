class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        int n = s.size();
        for ( auto i : s ) {
            bool check = true;
            if ( st.size() ) {
                if ( st.top() == 'A' && i == 'B' ) {
                    st.pop();
                    n -= 2;
                    check = false;
                } else if ( st.top() == 'C' && i == 'D' ) {
                    st.pop();
                    n -= 2;
                    check = false;
                }
            }
            if ( check ) st.push(i);
        }
        return n;
    }
};
