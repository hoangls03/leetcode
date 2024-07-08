class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        int furthest_point = 0;
        int count0 = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            furthest_point = max(i,furthest_point);
            while ( furthest_point < n && count0 <= k ) {
                if ( nums[furthest_point] == 0 ) {
                    count0++;
                }
                if ( count0 > k ) {
                    count0--;
                    break;
                }
                furthest_point++;
            }
            ans = max(furthest_point-i,ans);
            if ( nums[i] == 0 && i < furthest_point ) count0--;
        }
        return ans;
    }
};
