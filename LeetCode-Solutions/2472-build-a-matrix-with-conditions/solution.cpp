class Solution {
public:
    void topo_sort(vector<int>& topo, vector<vector<int>>& conditions, int& k ) {
        int m = conditions.size();
        vector<int> degree(k + 1);
        vector<vector<int>> g(k + 1);

        for ( int i = 0 ; i < m ; ++i ) {
            int u = conditions[i][1];
            int v = conditions[i][0];
            g[u].push_back(v);
            degree[v]++;
        }
        queue<int> source;
        for ( int i = 1 ; i <= k ; ++i ) {
            if ( !degree[i] ) source.push(i);
        }
        while ( source.size() ) {
            int u = source.front();
            source.pop();
            topo.push_back(u);
            for ( auto v : g[u] ) {
                degree[v]--;
                if ( !degree[v] ) source.push(v);
            }
        }
        reverse(topo.begin(),topo.end());
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> mark(k+1,0);
        vector<vector<int>> ans(k,vector<int>(k,0));
        vector<int> row;
        topo_sort(row,rowConditions,k);
        if ( row.size() < k ) {
            return {};
        }
        for ( int i = 0 ; i < row.size() ; ++i ) {
            mark[row[i]] = i;
        }
        vector<int> col;
        topo_sort(col,colConditions,k);
        if ( col.size() < k ) {
            return {};
        }
        for ( int i = 0 ; i < col.size() ; ++i ) {
            ans[mark[col[i]]][i] = col[i];
        }
        return ans;
    }
};
