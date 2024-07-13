class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        stack<int> st;
        vector<int> ans;
        int n = positions.size();
        vector<int> mark(n,1);
        map<int,int> position;
        for ( int i = 0 ; i < n ; ++i ) {
            position[positions[i]] = i;
        }
        sort(positions.begin(),positions.end());
        for ( int i = 0 ; i < n ; ++i ) {
            int current = position[positions[i]];
            if ( directions[current] == 'L' ) {
                while ( st.size() && mark[current] == 1 ) {
                    int pos = st.top();
                    if ( healths[pos] >= healths[current] ) {
                        mark[current] = 0;
                        if ( healths[pos] == healths[current] ) {
                            mark[pos] = 0;
                            st.pop();
                        }
                        healths[pos]--;
                    } else {
                        mark[pos] = 0;
                        healths[current]--;
                        st.pop();
                    }
                }
            } else {
                st.push(current);
            }
        }
        for ( int i = 0 ; i < n ; ++i ) {
            if ( mark[i] == 1 ) {
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};
