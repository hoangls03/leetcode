class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(),start.end());
        long long l = 0;
        long long r = 1e18;
        int n = start.size();
        long long ans = 1e18;
        while ( l <= r ) {
            long long mid = ( l + r ) >> 1;
            long long temp = start[0];
            bool check = true;
            for ( int i = 1 ; i < n && check ; ++i ) {
                long long val = start[i];
                if ( val + d < temp + mid ) {
                    check = false;
                }
                temp = max(temp + mid,val);
            }
            if ( check ) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
