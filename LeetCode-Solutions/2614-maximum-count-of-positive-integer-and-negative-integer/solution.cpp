class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int neg = 0, pos = 0;
        for ( auto i : nums ) {
            neg += ( i < 0 );
            pos += ( i > 0 );
        }
        return max(pos,neg);
    }
};
