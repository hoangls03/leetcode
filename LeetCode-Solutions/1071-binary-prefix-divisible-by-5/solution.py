class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        ans = []
        num = 0
        for x in nums:
            num = num*2 + x
            if num % 5 == 0:
                ans.append(True)
            else:
                ans.append(False)
        return ans
