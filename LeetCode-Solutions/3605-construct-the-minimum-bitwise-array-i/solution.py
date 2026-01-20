class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        ans = []
        for x in nums:
            val = -1
            for i in range(x):
                if (i | (i+1)) == x:
                    val = i
                    break
            ans.append(val)
        return ans

