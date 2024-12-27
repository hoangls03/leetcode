class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int val = values[0];
        int ans = -1e9;
        for ( int i = 1 ; i < n ; ++i ) {
            ans = max(ans,values[i] - i + val);
            val = max(val,values[i] + i);
        }
        return ans;
    }
};
