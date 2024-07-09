class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double wait = 0;
        int total_time = 0;
        int n = customers.size();
        for ( int i = 0 ; i < n ; ++i ) {
            int arrival = customers[i][0];
            int time = customers[i][1];
            total_time = max(total_time,arrival) + time;
            wait += total_time - arrival;
        }
        double ans = wait/n;
        return ans;
    }
};
