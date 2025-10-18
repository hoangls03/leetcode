class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;
        int prev = -1e9;
        for ( auto i : nums ) {
            int l = max(i - k, prev + 1);
            if ( l <= i + k ) {
                prev = l;
                ans++;
            }
        }
        return ans;
    }
};
