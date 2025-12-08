class Solution:
    def countTriples(self, n: int) -> int:
        ans = 0
        for x in range(1,n + 1):
            for y in range(1,n + 1):
                z = x*x + y*y
                m = int(sqrt(z))
                if ( m*m == z and m <= n ):
                    ans += 1
        return ans
