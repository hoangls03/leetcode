class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int localMin = 1e9;
        int localMax = -1e9;
        int pos = 0;
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            localMin = min(localMin,arr[i]);
            localMax = max(localMax,arr[i]);
            if ( localMin == pos && localMax == i ) {
                pos = i + 1;
                localMin = 1e9;
                localMax = -1e9;
                ans++;
            }
        }
        return ans;
    }
};
