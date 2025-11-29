class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = [0]*(n + 2)
        #dp[0] = 0
        #dp[1] = 0
        cost.append(0)
        for i in range(2,n + 2):
            dp[i] = min(dp[i-1] + cost[i-1],dp[i-2] + cost[i-2])
        return min(dp[n],dp[n+1])
