class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        bool check1 = true,check2 = true,check3 = true;
        
        for ( int j = 1; j < n - 2 && check1;  ++j ) {
            if ( nums[j] <= nums[j-1] ) {
                check1 = false;
            }
            if ( check1 ) {
                check2 = true;
                for ( int z = j + 1 ; z < n - 1 && check2; ++z ) {
                    if ( nums[z] >= nums[z-1] ) {
                        check2 = false;
                    }
                    if ( check2 ) {
                        check3 = true;
                        for ( int k = z + 1 ; k < n && check3; ++k ) {
                            if ( nums[k] <= nums[k-1] ) {
                                check3 = false;
                            }
                        }
                        if ( check3 ) return true;
                    }
                }
            }
        }
        
        return false;
    }
};
