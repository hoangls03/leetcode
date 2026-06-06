class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ans;
        int sum = 0;
        for ( auto i : nums ) {
            sum += i;
        }
        int curSum = 0;
        for ( auto i : nums ) {
            int res = abs(curSum*2 - sum + i);
            ans.push_back(res);
            curSum += i;
        }
        return ans;
    }
};
