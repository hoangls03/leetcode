class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        ans = nums[0]
        nums = nums[1:]
        nums.sort()
        ans += nums[0] + nums[1]
        return ans
