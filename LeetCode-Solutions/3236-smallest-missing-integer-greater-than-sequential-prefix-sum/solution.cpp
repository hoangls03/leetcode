class Solution {
public:
    int missingInteger(vector<int>& nums) {
        vector<int> mark(100005,0);
        nums.push_back(0);
        int n = nums.size();
        for ( auto i : nums ) {
            mark[i]++;
        }
        int len = 1, maxLen = 1, localSum = nums[0], ans = nums[0];
        for ( int i = 1 ; i < n ; ++i ) {
            if ( nums[i] == nums[i-1] + 1) {
                len++;
                localSum += nums[i];
            } else {
                if ( len > maxLen ) {
                    maxLen = len;
                    ans = localSum;
                } 
                if ( len == maxLen ) {
                    ans = min(ans,localSum);
                }
                len = 1;
                localSum = nums[i];
                break;
            }
        }
        while ( mark[ans] != 0 ) {
            ans++;
        }
        return ans;
    }
};
