class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        ans = []
        for x in nums:
            s = bin(x)[2:]
            print(s)
            if (s[-1] == '0' ):
                ans.append(-1)
                continue
            countOne = 0
            pos = -1
            for i in range(len(s) - 1, -1, -1):
                if ( s[i] == '1' ):
                    countOne += 1
                else:
                    pos = i + 1
                    break
            t = s
            if ( countOne == len(s) ):
                t = int(s[1:],2)
            else:
                if ( countOne >= 2 ):
                    s = s[:pos] + '0' + s[pos + 1:]
                    t = int(s,2)
                else:
                    s = s[:-1] + '0'
                    t = int(s,2)
            ans.append(t)
                 
        return ans
