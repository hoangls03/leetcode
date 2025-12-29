class Solution {
public:
    bool cal(string s, map<string,bool>& vis, vector<vector<vector<char>>>& nextChar ) {
        if ( s.size() == 1 ) return true;
        if ( vis[s] ) return false;
        vis[s] = true;
        set<string> st;
        st.insert("");
        int n = s.size();
        for ( int i = 1 ; i < n ; ++i ) {
            if ( nextChar[s[i-1]][s[i]].size() ) {
                set<string> st1;
                for ( char ch : nextChar[s[i-1]][s[i]] ) {
                    for ( auto& j : st ) {
                        st1.insert(j + ch);
                    }
                }
                st = st1;
            } else {
                return false;
            }
        }
        for ( auto i : st ) {
            if ( cal(i,vis,nextChar) ) return true;
        }
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        map<string,int> mark;
        vector<vector<vector<char>>> nextChar('F' + 5,vector<vector<char>>('F' + 5));
        for ( auto i : allowed ) { 
            nextChar[i[0]][i[1]].push_back(i[2]);
            mark[i] = 1;
        }
        map<string,bool> vis;
        return cal(bottom,vis,nextChar);
    }
};
