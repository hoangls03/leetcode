class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long odd = 1, even = 2, sumOdd = 0, sumEven = 0;
        while ( n-- ) {
            sumOdd += odd;
            sumEven += even;
            odd += 2;
            even += 2;
        }
        return __gcd(sumOdd,sumEven);
    }
};
