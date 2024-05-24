class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }
    void BFS( map<int,vector<int>>& g, set<int>& st, vector<int>& mark ) {
        queue<int> q;
        for ( auto i : st ) {
            q.push(i);
            cout<<i<<'\n';
        }
        while ( q.size() ) {
            int u = q.front();
            q.pop();
            for ( auto v : g[u] ) {
                if ( mark[v] == 0 ) {
                    mark[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> mark(n,0);
        for ( int i = 0 ; i < n ; ++i ) {
            mark[i] = 0;
        }
        mark[0] = 1;
        mark[firstPerson] = 1;
        sort(meetings.begin(),meetings.end(),cmp);
        vector<vector<int>> times(1e5+1);
        map<int,vector<int>> g;
        set<int> st;
        for ( int i = 0 ; i < meetings.size() ; ++i ) {
            if ( i > 0 && meetings[i][2] != meetings[i-1][2] ) {
                BFS(g,st,mark);
                g.clear();
                st.clear();
            }
            if ( mark[meetings[i][0]] == 1 ) st.insert(meetings[i][0]);
            if ( mark[meetings[i][1]] == 1 ) st.insert(meetings[i][1]);
            //cout<<meetings[i][0]<<" "<<meetings[i][1]<<'\n';
            g[meetings[i][0]].push_back(meetings[i][1]);
            g[meetings[i][1]].push_back(meetings[i][0]);
            if ( i == meetings.size() - 1 ) {
                BFS(g,st,mark);
                g.clear();
                st.clear();
            }
        }
        
        vector<int> ans;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( mark[i] == 1 ) ans.push_back(i);
        }
        return ans;
    }
};
