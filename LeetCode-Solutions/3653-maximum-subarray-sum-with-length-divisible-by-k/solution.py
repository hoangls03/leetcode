class Solution:
    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        mark = [0]*k
        sum = 0
        ans = -10**15
        for i in range(n):
            sum += nums[i]
            if ( i < k - 1 ):
                mark[(i+1)%k] = sum
            if ( i == k - 1 ): ans = sum
            ans = max(ans,sum - mark[(i+1)%k])
            mark[(i+1)%k] = min(mark[(i+1)%k],sum)
        
        return ans
                

