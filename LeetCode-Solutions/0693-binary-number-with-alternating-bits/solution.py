class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        n = bin(n)[2:]
        ans = True
        for i in range(1,len(n)):
            if n[i] == n[i-1]:
                ans = False
        return ans
