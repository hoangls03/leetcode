class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(101,0);
        for ( int i = n - 1 ; i >= 0 ; --i ) {
            count[nums[i]]++;
            if ( count[nums[i]] >= 2 ) {
                return ((i+1)/3) + ((i+1) % 3 != 0);
            }
        }
        return 0;
    }
};
