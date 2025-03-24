class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int n = meetings.size();
        int ans = 0;
        int r = meetings[0][1];
        ans += meetings[0][0] - 1;
        for ( int i = 1 ; i < n ; ++i ) {
            ans += max(meetings[i][0] - r - 1,0);
            r = max(r,meetings[i][1]);
        }
        ans += days - r;
        return ans;
    }
};
