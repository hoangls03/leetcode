class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        ans = 0
        for row in grid:
            for i in row:
                if i < 0:
                    ans += 1
        return ans
