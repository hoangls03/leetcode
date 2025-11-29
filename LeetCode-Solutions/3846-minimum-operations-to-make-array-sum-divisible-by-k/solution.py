class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        sum = 0
        for x in nums:
            sum += x
        return sum % k
