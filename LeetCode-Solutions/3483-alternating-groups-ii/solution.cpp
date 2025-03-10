class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for ( int i = 0 ; i < k - 1 ; ++i ) {
            colors.push_back(colors[i]);
        }
        int n = colors.size();
        int ans = 0;
        int l = 0;
        for ( int i = 1 ; i < n ; ++i ) {
            if ( colors[i] == colors[i-1] ) {
                l = i;
            }
            if ( i - l + 1 >= k ) ans++;
        }
        return ans;
    }
};
