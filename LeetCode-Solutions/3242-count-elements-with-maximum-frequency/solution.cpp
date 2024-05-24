class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> mark(101,0);
        int ans = 0, s = 0;
        for ( int i = 0 ; i < nums.size() ; ++i ) {
            mark[nums[i]]++;
            if ( mark[nums[i]] == s ) {
                ans += mark[nums[i]];
            }
            if ( mark[nums[i]] > s ) {
                s = mark[nums[i]];
                ans = mark[nums[i]];
            }
        }
        return ans;
    }
};
