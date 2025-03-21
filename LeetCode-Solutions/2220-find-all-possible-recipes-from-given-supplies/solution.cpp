class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string> save(supplies.begin(), supplies.end());
        vector<int> d(n,0);
        map<string,vector<int>> g;
        for ( int i = 0 ; i < n ; ++i ) {
            for ( auto s : ingredients[i] ) {
                if ( !save.count(s) ) {
                    g[s].push_back(i);
                    d[i]++;
                }
            }
        }

        queue<int> q;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( d[i] == 0 ) {
                q.push(i);
            }
        }
        vector<string> ans;
        while ( q.size() ) {
            int u = q.front();
            q.pop();
            auto s = recipes[u];
            ans.push_back(s);
            for ( auto i : g[s] ) {
                d[i]--;
                if ( d[i] == 0 ) q.push(i);
            }
        }
        return ans;
    }
};
