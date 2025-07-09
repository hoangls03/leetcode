class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeTime;
        int n = startTime.size();
        startTime.push_back(eventTime);
        for ( int i = 0 ; i <= n ; ++i ) {
            if ( i == 0 ) {
                freeTime.push_back(startTime[i]);
            } else {
                freeTime.push_back(startTime[i] - endTime[i-1]);
            }
        }
        n = freeTime.size();
        vector<int> sum(n,0);
        sum[0] = freeTime[0];
        for ( int i = 1 ; i < n ; ++i ) {
            sum[i] = sum[i-1] + freeTime[i];
        }
        int ans = 0,l;
        for ( int i = 0 ; i < n ; ++i ) {
            int l = 0;
            if ( i != 0 ) l = sum[i-1]; 
            int r = min(i+k,n-1);
            ans = max(ans,sum[r] - l);
        }
        return ans;
    }
};
