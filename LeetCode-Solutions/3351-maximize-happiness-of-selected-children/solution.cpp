class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long n = happiness.size();
        sort(happiness.begin(),happiness.end());
        long long ans = 0,temp = 0;
        for ( int i = n - 1 ; i >= 0 ; --i ) {
            if ( k > 0 ) {
                ans += max(happiness[i] - ( n-1 - (i) ),temp);
                k--;
            }
        }
        return ans;
    }
};
