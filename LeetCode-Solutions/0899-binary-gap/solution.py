class Solution:
    def binaryGap(self, n: int) -> int:
        n = bin(n)[2:]
        lenN = len(n)
        prev = -1
        ans = 0
        for i in range(lenN):
            if n[i] == '1':
                if prev != -1:
                    ans = max(ans,i - prev)
                prev = i
        return ans
