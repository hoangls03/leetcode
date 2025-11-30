class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        n = len(nums)
        sum = [0]*n
        sum[0] = nums[0]
        for i in range(1,n):
            sum[i] = sum[i-1] + nums[i]
        
        mark = {}
        mark[0] = n - 1
        ans = n
        for i in range(n - 1,-1,-1):
            if ( (sum[n - 1] - sum[i] + nums[i]) %p == 0 ):
                ans = min(ans,i)
            y = (p - sum[i]%p)%p
            if ( y in mark ):
                ans = min(ans,mark[y] - i)
            x = (sum[n-1] - sum[i])%p
            mark[x] = i

        if (ans == n):
            ans = -1
        return ans

