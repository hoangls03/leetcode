class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        index = 0
        res = []
        n = len(nums)
        for i in range(n):
            index = i
            x = nums[i]
            index += x
            index %= n
            if index < 0:
                index += n - 1
            res.append(nums[index]) 
        return res
