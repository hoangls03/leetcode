class Solution:
    def judgeCircle(self, moves: str) -> bool:
        u = 0
        l = 0
        for i in moves:
            if i == 'U':
                u += 1
            if i == 'D':
                u -= 1
            if i == 'L':
                l += 1
            if i == 'R':
                l -= 1
        return (u == 0 and l == 0)
