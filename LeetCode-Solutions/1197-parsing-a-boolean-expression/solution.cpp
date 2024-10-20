class Solution {
public: 
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for ( auto i : expression ) {
            if ( i == '(' || i == ',' ) continue;
            else if ( i != ')' ) {
                st.push(i);
            } else {
                bool True = false, False = false;
                while ( st.top() == 't' || st.top() == 'f' ) {
                    if ( st.top() == 't' ) True = true;
                    if ( st.top() == 'f' ) False = true;
                    st.pop(); 
                }
                char curr = st.top();
                st.pop();
                if ( curr == '!' ) {
                    st.push(True ? 'f' : 't');
                }
                if ( curr == '&' ) {
                    st.push(False ? 'f' : 't');
                }
                if ( curr == '|' ) {
                    st.push(True ? 't' : 'f');
                }
            }
        }
        return st.top() == 't';
    }
};
