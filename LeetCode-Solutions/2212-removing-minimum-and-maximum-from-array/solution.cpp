class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minNum = 1e9, maxNum = -1e9, minPos = -1, maxPos = -1;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( nums[i] > maxNum ) {
                maxNum = nums[i];
                maxPos = i;
            }
            if ( nums[i] < minNum ) {
                minNum = nums[i];
                minPos = i;
            }
        }
        int ans = 1e9;
        ans = min({ans, max(minPos,maxPos) + 1, n - min(minPos,maxPos), min(minPos,maxPos) + 1 + n - max(minPos,maxPos)});
        return ans;
    }
};
