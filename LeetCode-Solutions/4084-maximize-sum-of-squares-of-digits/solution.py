class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        ans = ""
        while sum >= 9:
            sum -= 9
            ans += '9'
        if ( sum > 0):
            ans += str(sum)
        if ( len(ans) > num ):
            return ""
        while ( len(ans) < num ):
            ans += "0"
        return ans
