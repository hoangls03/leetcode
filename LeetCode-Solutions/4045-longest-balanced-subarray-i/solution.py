class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        for i in range(n):
            mp = {}
            countOdd = 0
            countEven = 0
            for j in range(i,n):
                x = nums[j]
                mp[x] = mp.get(nums[j],0) + 1
                if mp[x] == 1:
                    if x % 2 == 0:
                        countEven += 1
                    else:
                        countOdd += 1
                if ( countOdd == countEven ):
                    ans = max(ans,j - i + 1)

        return ans
            
