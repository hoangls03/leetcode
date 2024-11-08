class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int temp = ( 1 << maximumBit ) - 1;
        vector<int> ans;
        int sumXor = 0;
        for ( auto i : nums ) {
            sumXor ^= i;
            ans.push_back(sumXor^temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
