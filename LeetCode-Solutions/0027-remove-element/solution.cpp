class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        for ( auto& i : nums ) {
            if ( i == val ) {
                i = 51;
                n--;
            }
        }
        sort(nums.begin(),nums.end());
        for ( auto& i : nums ) {
            if ( i == 51 ) {
                i = val;
            }
        }
        return n;
    }
};
