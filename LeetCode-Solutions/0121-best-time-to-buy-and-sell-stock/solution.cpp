class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minNum = 1e4;
        for ( auto i : prices ) {
            ans = max(i - minNum,ans);
            minNum = min(minNum,i);
        }
        return ans;
    }
};
