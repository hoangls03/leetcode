class Solution:
    def longestBalanced(self, s: str) -> int:
        mp = {}
        n = len(s)
        ans = 1
        for i in range(n):
            mp = {}
            for j in range(i,n):
                mp[ord(s[j])] = mp.get(ord(s[j]),0) + 1
                val = 0
                check = True
                for z in range(ord('a'),ord('z') + 1):
                    if mp.get(z,0) != 0:
                        if val == 0:
                            val = mp[z]
                        else:
                            if val != mp[z]:
                                check = False
                if (check):
                    ans = max(ans,j-i+1)
        return ans
