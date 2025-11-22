class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        ans = 0
        for x in nums:
            x %= 3
            ans += min(x,3-x)
        return ans
        
