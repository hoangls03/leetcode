class Solution {
public:
    void DFS(int u, vector<vector<int>>& g, vector<int>& d, string& s, int& ans) {
        if ( d[u] != 0 ) {
            return ;
        }
        d[u] = 1;
        vector<int> nums;
        for ( auto v : g[u] ) {
            DFS(v,g,d,s,ans);
            if ( s[v] != s[u] ) {
                nums.push_back(d[v]);
            }
        }
        sort(nums.rbegin(),nums.rend());
        if ( nums.size() == 1 ) {
            d[u] += nums[0];
        } else if ( nums.size() >= 2 ) {
            d[u] += nums[0];
            ans = max(ans,nums[0] + nums[1] + 1);
        }
        ans = max(ans,d[u]);
    }
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        vector<vector<int>> g(n);
        vector<int> d(n,0);
        int ans = 0;
        for ( int i = 1 ; i < n ; ++i ) {
            g[parent[i]].push_back(i);
        }

        DFS(0,g,d,s,ans);
        return ans;
    }
};
