class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        m = len(grid)
        ans = 0
        for i in range(m):
            pos = -1
            for j in range(i,len(grid)):
                count0 = 0
                for k in range(len(grid[j]) - 1,-1,-1):
                    if (grid[j][k] == 0):
                        count0 += 1
                    else:
                        break
                if ( count0 >= m - i - 1 ):
                    ans += j - i
                    pos = j
                    break
            if ( pos == -1 ):
                return -1
            for j in range(pos,i,-1):
                grid[j] = grid[j-1]       
        return ans
