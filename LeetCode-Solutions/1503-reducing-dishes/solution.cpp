class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        int ans = 0;
        int sum = 0;
        int array_sum = 0;
        for ( int  i = n - 1 ; i >= 0 ; --i ) {
            array_sum = array_sum + satisfaction[i];
            sum += array_sum;
            ans = max(ans,sum);
        }
        return ans;
    }
};
