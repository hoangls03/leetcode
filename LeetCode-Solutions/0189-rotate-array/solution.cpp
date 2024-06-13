class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        vector<int> clone;
        for ( auto i : nums ) {
            clone.push_back(i);
        }
        int pos = 0;
        for ( int i = n - k ; i < n ; ++i ) {
            nums[pos++] = clone[i];
        }
        for ( int i = 0 ; i < n - k ; ++i ) {
            nums[pos++] = clone[i];
        }
    }
};
