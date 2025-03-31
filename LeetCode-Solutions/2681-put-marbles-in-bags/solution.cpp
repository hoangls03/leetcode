class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<long long> weightSum;
        long long sumMax = 0, sumMin = 0;
        for ( int i = 0 ; i < n - 1 ; ++i ) {
            weightSum.push_back(weights[i] + weights[i+1]);
        }
        sort(weightSum.begin(),weightSum.end());
        int m = weightSum.size();        
        for ( int i = m - 1 ; i >= m - k + 1 ; --i ) {
            sumMax += weightSum[i];
        }
        for ( int i = 0 ; i < k - 1 ; ++i ) {
            sumMin += weightSum[i];
        }
        return sumMax - sumMin;
    }
};
