class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int m = landStartTime.size();
        int n = waterStartTime.size();
        int ans = 1e9;
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( landStartTime[i] <= waterStartTime[j] ) {
                    int nextStart = max(landStartTime[i] + landDuration[i], waterStartTime[j]);
                    ans = min(ans,nextStart + waterDuration[j]);
                } else {
                    int nextStart = max(landStartTime[i], waterStartTime[j] + waterDuration[j]);
                    ans = min(ans,nextStart + landDuration[i]);
                }
            }
        }
        return ans;
    }
};
