class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        while ( nums.size() > 1 ) {
            bool ok = true;
            int minSum = 1e9;
            int pos = -1;
            int n = nums.size();
            for ( int i = 0 ; i < n - 1; ++i ) {
                int sum = nums[i] + nums[i+1];
                if ( nums[i] > nums[i+1] ) {
                    ok = false;
                }
                if ( sum < minSum ) {
                    pos = i;
                    minSum = sum;
                }
            }
            if ( ok ) {
                break;
            }
            ans++;
            nums[pos] = minSum;
            nums.erase(nums.begin() + pos + 1);
        }
        return ans;
    }
};
