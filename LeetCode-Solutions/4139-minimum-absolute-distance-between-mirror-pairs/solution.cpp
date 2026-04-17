class Solution {
public:
    int rev( int n ) {
        int ans = 0;
        while ( n > 0 ) {
            ans = ans * 10 + n % 10;
            n /= 10;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        map<int,int> mark, markReverse;
        int n = nums.size();
        int ans = 1e9;
        for ( int i = 0 ; i < n ; ++i ) {
            
            if ( markReverse[nums[i]] != 0 ) {
                ans = min(ans,i - markReverse[nums[i]] + 1);
            }
            int tmp = rev(nums[i]);
            markReverse[tmp] = i + 1;
        }
        if ( ans == 1e9 ) ans = -1;
        return ans;
    }
};
