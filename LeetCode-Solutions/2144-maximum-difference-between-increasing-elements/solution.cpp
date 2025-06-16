class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minNum = 1e9;
        int ans = -1e9;
        for ( auto i : nums ) {
            if ( minNum < i ) ans = max(ans,i-minNum);
            minNum = min(minNum,i);
        }
        if ( ans == -1e9 ) ans = -1;
        return ans;
    }
};
