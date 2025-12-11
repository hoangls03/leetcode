class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<set<int>> markX(n + 1),markY(n + 1);
        for ( auto build : buildings ) {
            markX[build[0]].insert(build[1]);
            markY[build[1]].insert(build[0]);
        }
        int ans = 0;
        for ( auto build : buildings ) {
            int first = *markX[build[0]].begin();
            int last = *markX[build[0]].rbegin();
            if ( build[1] == first || build[1] == last ) {
                continue;
            }
            first = *markY[build[1]].begin();
            last = *markY[build[1]].rbegin();
            if ( build[0] == first || build[0] == last ) {
                continue;
            }
            ans++;
        }
        return ans;
    }
};
