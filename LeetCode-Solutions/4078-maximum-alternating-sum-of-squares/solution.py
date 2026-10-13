class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        nums = [abs(num) for num in nums]
        nums.sort()
        ans = 0
        n = len(nums)
        for i in range(len(nums)):
            if i < n//2:
                ans -= nums[i]**2
            else:
                ans += nums[i]**2
        return ans
