class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[-1] * 3 for _ in range(n)]
        dp[0][0] = 0
        for i in range(n):
            if i == 0:
                dp[i][nums[i]%3] = nums[i]
            else:
                for j in range(3):
                    dp[i][j] = dp[i-1][j]
                for j in range(3):
                    if dp[i-1][j] != -1: dp[i][(j + nums[i])% 3] = max(dp[i][(j + nums[i])% 3],dp[i-1][j] + nums[i])
        return dp[n-1][0]
