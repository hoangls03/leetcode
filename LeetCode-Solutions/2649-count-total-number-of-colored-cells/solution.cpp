class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1LL*(n-1)*n*2 + 1;
        return ans;
    }
};
