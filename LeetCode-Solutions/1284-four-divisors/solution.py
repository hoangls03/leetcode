class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        ans = 0
        for x in nums:
            sum = 0
            numDiv = 0
            for i in range(1,int(sqrt(x)) + 1):
                if x % i == 0:
                    numDiv += 2
                    sum += i
                    sum += x/i
                    if (i*i == x):
                        numDiv -= 1
                        sum -= i
            if ( numDiv == 4 ):
                ans += int(sum)
        return ans

                

