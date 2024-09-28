class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(),maximumHeight.end());
        int n = maximumHeight.size();
        long long ans = 0;
        ans += maximumHeight[n-1];
        int temp = maximumHeight[n-1] - 1;
        for ( int i = n - 2 ; i >= 0 ; --i ) {
            temp = min(temp,maximumHeight[i]);
            if ( temp <= 0 ) return -1;
            ans += temp;
            temp--;
        }
        return ans;
    }
};
