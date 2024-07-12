class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        int run = 2;
        int n = s.size();
        vector<int> mark(n,0);
        while ( run-- ) {
            stack<int> st;
            for ( int i = 0 ; i < s.size() ; ++i ) {
                if ( mark[i] == 0 ) {
                    if ( st.size() ) {
                        if ( x > y ) {
                            if ( s[i] == 'b' && s[st.top()] == 'a' ) {
                                mark[i] = 1;
                                mark[st.top()] = 1;
                                ans += x;
                                st.pop();
                            } else {
                                st.push(i);
                            }
                        } else {
                            if ( s[i] == 'a' && s[st.top()] == 'b' ) {
                                ans += y;
                                mark[i] = 1;
                                mark[st.top()] = 1;
                                st.pop();
                            } else {
                                st.push(i);
                            }
                        }
                    } else {
                        st.push(i);
                    }
                }
                
            }
            if ( x > y ) x = y - 1;
            else y = x - 1;
        }
        return ans;
    }
};
