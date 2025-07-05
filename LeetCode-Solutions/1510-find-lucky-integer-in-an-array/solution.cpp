class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> mark(501,0);
        for ( auto i : arr ) {
            mark[i]++;
        }
        int ans = -1;
        for ( auto i : arr ) {
            if ( i == mark[i] ) ans = max(ans,i);
        }
        return ans;
    }
};
