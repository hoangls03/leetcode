class Solution {
public:
    bool check( int n ) {
        if ( n <= 1 ) return false;
        if ( n == 2 ) return true;
        for ( int i = 2 ; i <= sqrt(n) ; ++i ) {
            if ( n % i == 0 ) return false;
        }
        return true;
    }
    bool primeSubOperation(vector<int>& nums) {
        for ( int i = 0 ; i < nums.size() ; ++i ) {
            int diff = nums[i];
            if ( i != 0 ) {
                diff -= nums[i-1];
            }
            if ( diff <= 0 ) return false;
            for ( int j = diff - 1; j >= 2 ; --j ) {
                if ( check(j) ) {
                    nums[i] -= j;
                    break;
                }
            }
            
        }
        return true;
    } 
};
