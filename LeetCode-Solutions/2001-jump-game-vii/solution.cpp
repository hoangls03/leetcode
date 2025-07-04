class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> st;
        int n = s.size();
        st.push(0);
        for ( int i = 1 ; i < n ; ++i ) {
            if ( s[i] == '0' ) {
                while ( st.size() && st.front() + maxJump < i ) {
                    st.pop();
                }
                if ( st.size() && st.front() + minJump <= i && st.front() + maxJump >= i ) {
                    if ( i == n - 1 ) return true;
                    st.push(i);
                }
            }
        }
        return false;
    }
};
