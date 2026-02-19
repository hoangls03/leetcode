class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        n = len(s)
        ans = 0
        count0 = 0
        count1 = 0
        prev = -1
        for i in s:
            if i == '0':
                if prev == '1':
                    count0 = 0
                count0 += 1
                if count1 >= count0:
                    ans += 1
            if i == '1':
                if prev == '0':
                    count1 = 0
                count1 += 1
                if count0 >= count1:
                    ans += 1
            prev = i
        return ans
