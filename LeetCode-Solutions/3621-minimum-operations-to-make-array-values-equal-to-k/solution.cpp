class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int count = 0;
        for ( int i = 0 ; i < n - 1 ; ++i ) {
            count+= (nums[i] != nums[i+1]);
        }
        if ( k > nums[0] ) return -1;
        if ( k == nums[0] ) return count;
        return count + 1;
    }
};
