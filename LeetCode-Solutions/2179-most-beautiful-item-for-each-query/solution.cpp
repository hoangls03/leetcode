class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        vector<int> ans;
        int n = items.size();
        vector<int> mark(n,0);
        mark[0] = items[0][1];
        for ( int i = 1 ; i < n ; ++i ) {
            mark[i] = max(mark[i-1],items[i][1]);
        }
        for ( auto i : queries ) {
            int l = 0;
            int r = n - 1;
            int pos = -1;
            while ( l <= r ) {
                int mid = ( l + r ) >> 1;
                if ( items[mid][0] <= i ) {
                    pos = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if ( pos != -1 ) ans.push_back(mark[pos]);
            else ans.push_back(0);
        }
        return ans;
    }
};
