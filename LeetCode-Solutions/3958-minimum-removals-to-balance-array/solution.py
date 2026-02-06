class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        n = len(nums)
        l = 1
        r = n
        nums.sort()
        ans = n - 1
        while ( l <= r ):
            mid = int((l + r)/2)
            check = False
            for i in range(n - mid + 1):
                if nums[i]*k >= nums[i + mid - 1]:
                    check = True
                    break
            if check:
                l = mid + 1
                ans = min(ans, n - mid)
            else:
                r = mid - 1
        return ans
