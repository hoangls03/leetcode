class Solution {
public:
    bool checkDivisibility(int n) {
        int m = n;
        long long ans = 0, sum = 0, prod = 1;
        while ( n != 0 ) {
            sum += n%10;
            prod *= n%10;
            n /= 10;
        }
        ans = sum + prod;
        return ( m % ans == 0 );
    }
};
