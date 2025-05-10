class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0, zero1 = 0, zero2 = 0;
        for ( auto i : nums1 ) {
            sum1 += i;
            zero1 += ( i == 0 );
        }
        for ( auto i : nums2 ) {
            sum2 += i;
            zero2 += ( i == 0 );
        }
        if ( sum1 + zero1 == sum2 + zero2 ) {
            return sum1 + zero1;
        }
        if ( zero1 == 0 && zero2 == 0 ) {
            return -1;
        } else if ( zero1 == 0 && sum1 < sum2 + zero2) {
            return -1;
        } else if ( zero2 == 0 && sum1 + zero1 > sum2 ) {
            return -1;
        }
        return max(sum1 + zero1, sum2 + zero2);
    }
};
