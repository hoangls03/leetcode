class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int ans = -1e9;
        vector<int> sum(n,0);
        for ( int i = n - 1 ; i >= 0 ; --i ) {
            int extra = 0;
            if ( i + k < n ) {
                extra = sum[i+k];
            }
            sum[i] = extra + energy[i];
            ans = max(ans,sum[i]);
        }
        return ans;
    }
};
