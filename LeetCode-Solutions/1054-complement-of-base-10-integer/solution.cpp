class Solution {
public:
    int bitwiseComplement(int n) {
        if ( n == 0 ) return 1;
        long long m = log2(n);
        m = (1 << (m + 1)) - 1;
        return m ^ n;
    }
};
