class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        map<int,vector<int>> adj;
        map<int,int> deg;
        for ( auto e : pairs ) {
            adj[e[0]].push_back(e[1]);
            deg[e[0]]++;
            deg[e[1]]--;
        }
        int start = pairs[0][0];
        for ( auto e : deg ) {
            if ( e.second == 1 ) {
                start = e.first;
                break;
            }
        }
        vector<int> path;
        stack<int> st;
        st.push(start);

        while ( st.size() ) {
            auto& u = adj[st.top()];
            if ( u.empty() ) {
                path.push_back(st.top());
                st.pop();
            } else {
                st.push(u.back());
                u.pop_back();
            }
        }
        vector<vector<int>> ans;
        for ( int i = path.size() - 1 ; i > 0 ; --i ) {
            ans.push_back({path[i],path[i-1]});
        }
        return ans;
    }
};
