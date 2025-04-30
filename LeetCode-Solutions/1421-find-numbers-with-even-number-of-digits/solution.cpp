class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for ( auto i : nums ) {
            int digit = 0;
            if ( i == 0 ) digit = 1;
            while ( i > 0 ) {
                digit++;
                i /= 10;
            }
            ans += ( digit % 2 == 0 );
        }
        return ans;
    }
};
