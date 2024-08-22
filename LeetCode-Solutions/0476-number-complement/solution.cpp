class Solution {
public:
    int findComplement(int num) {
        int pos = log2(num) + 1;
        long long ans = ( 1 << pos );
        ans -= 1;
        ans ^= num;
        return ans;
    }
};
