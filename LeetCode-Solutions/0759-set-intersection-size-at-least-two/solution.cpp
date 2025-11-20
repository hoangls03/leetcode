class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),
            [](const vector<int>& a, const vector<int>&b) {
                return a[1] < b[1];
            });
        int second = intervals[0][1] - 1;
        int first = intervals[0][1];
        int ans = 2;
        int n = intervals.size();
        for ( int i = 1 ; i < n ; ++i ) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if ( first < start ) {
                first = end;
                second = first - 1;
                ans += 2;
            } else if ( second < start ) {
                second = end;
                second -= (first == end);
                if ( second > first ) {
                    swap(first,second);
                }
                ans += 1;
            }
        }
        return ans;
    }
};
