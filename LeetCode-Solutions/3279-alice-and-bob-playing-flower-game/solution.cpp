class Solution {
public:
    long long flowerGame(int n, int m) {
        int even = m/2;
        int odd = m - even;
        long long ans = 0;
        int evenN = n/2;
        int oddN = n - evenN;
        ans = 1LL*evenN*odd + 1LL*oddN*even;
        return ans;
    }
};
