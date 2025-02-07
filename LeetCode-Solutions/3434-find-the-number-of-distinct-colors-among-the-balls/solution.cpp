class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int> color;
        map<int,int> mark;
        vector<int> ans;
        int res = 0;
        for ( auto q : queries ) {
            mark[color[q[0]]]--;
            if ( mark[color[q[0]]] == 0 ) {
                res--;
            }
            color[q[0]] = q[1];
            if ( mark[q[1]] == 0 ) {
                res++;
            }
            mark[q[1]]++;
            ans.push_back(res);
        }
        return ans;
    }
};
