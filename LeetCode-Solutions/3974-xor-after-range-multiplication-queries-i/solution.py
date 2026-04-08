oo = 10**9 + 7
class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        for q in queries:
            l,r,k,v = q
            for i in range(l,r + 1,k):
                nums[i] = nums[i] * v % oo
        
        ans = -1
        for i in nums:
            if ( ans == -1 ):
                ans = i
            else:
                ans = ans ^ i
        return ans
