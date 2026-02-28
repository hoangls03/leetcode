class Solution:
    def concatenatedBinary(self, n: int) -> int:
        ans = 0
        x = 0
        for i in range(1,n + 1):
            while ( 2**x <= i ):
                x += 1
            ans = ans*(2**x) + i
            ans %= 10**9 + 7
        ans %= 10**9 + 7
        return ans
