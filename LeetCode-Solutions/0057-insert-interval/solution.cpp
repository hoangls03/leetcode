class Solution {
    static bool cmp( vector<int> &a, vector<int> &b ) {
        if ( a[0] == b[0] ) return a[1] < b[1];
        return a[0] < b[0];
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<int> interval(2,-1);
        int l =-1,r =-1;
        vector<vector<int>> ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),cmp);
        interval[0] = intervals[0][0];
        interval[1] = intervals[0][1];
        bool check = true;
        for ( int i = 1 ; i < intervals.size() ; ++i ) {
            check = true;
            //cout<<intervals[i][0]<<" "<<interval[1]<<'\n';
            if ( intervals[i][0] <= interval[1] ) {
                interval[1] = max(intervals[i][1],interval[1]);
            } else {
                ans.push_back(interval);
                interval[0] = intervals[i][0];
                interval[1] = intervals[i][1];
            }
        }
        ans.push_back(interval);
        return ans;
    }
};
