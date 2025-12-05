class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        sum = 0
        for x in nums:
            sum += x
        cur = 0
        n = len(nums)
        if sum % 2 == 1:
            return 0
        return n - 1
