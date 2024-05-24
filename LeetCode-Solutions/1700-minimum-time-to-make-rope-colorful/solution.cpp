class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        colors = " " + colors;
        colors += " ";
        int ans = 0,sum = 0, emax = -1;
        for ( int i = 1 ; i <= n + 1 ; ++i ) {
            if ( colors[i] == colors[i-1] ) {
                sum += neededTime[i-1];
                if ( emax == -1 ) sum += neededTime[i-2];
                emax = max(emax,max(neededTime[i-1],neededTime[i-2]));
            }
            else {
                if ( emax != -1 ) {
                    ans += sum - emax;
                    sum = 0;
                    emax = -1;
                }
            }
        }
        return ans;
    }
};
