class Solution:
    def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
        m = len(grid)
        n = len(grid[0])
        oo = 10**9 + 7
        dp = [[[0 for _ in range(k)] for _ in range(n)] for _ in range(m)]
        dp[0][0][grid[0][0]%k] = 1
        for i in range(m):
            for j in range(n):
                for kMod in range(k):

                    up = 0
                    if ( i > 0 ):
                        up = dp[i-1][j][kMod]
                    left = 0
                    if ( j > 0 ):
                        left = dp[i][j-1][kMod]
                    tmp = (kMod + grid[i][j])%k
                    dp[i][j][tmp] += up + left
                    dp[i][j][tmp] %= oo
        
        return dp[m-1][n-1][0]
                    
