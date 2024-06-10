class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> clone;
        for ( auto i : heights ) {
            clone.push_back(i);
        }
        sort(clone.begin(),clone.end());
        int ans = 0;
        int n = heights.size();
        for ( int i = 0 ; i < n ; ++i ) {
            if ( heights[i] != clone[i] ) ans++;
        }
        return ans;
    }
};
