class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = 1e9;
        for ( auto i : nums ) {
            ans = min(ans,i);
        }
        return ans;
    }
};
