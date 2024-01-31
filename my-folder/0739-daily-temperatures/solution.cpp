class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> mark(101,0),ans(temperatures.size());
        for ( int i = temperatures.size() - 1 ; i >= 0 ; --i ) {
            int temp = 1e5;
            for ( int j = temperatures[i] + 1; j <= 100 ; ++j ) {
                if ( mark[j] != 0 ) {
                    temp = min(temp,mark[j]-i);
                }
            }
            ans[i] = temp == 1e5 ? 0 : temp;
            mark[temperatures[i]] = i;
        }
        return ans;
    }
};
