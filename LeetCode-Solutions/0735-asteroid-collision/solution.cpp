class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for ( auto i : asteroids ) {
            if ( i < 0 && st.size() ) {
                while ( i < 0 && st.size() > 0 && st[st.size() - 1] > 0 && st[st.size() - 1] <= -i ) {
                    if ( st[st.size() - 1] == -i ) i = 0;
                    st.pop_back();
                }
                if ( st.size() > 0 && st[st.size() - 1] > 0 && st[st.size() - 1] > -i ) {
                    i = 0;
                }
            }
            if ( i != 0 ) {
                st.push_back(i);
            }
        }
        return st;
    }
};
