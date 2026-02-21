def isPrime(n: int):
    if n <= 1:
        return False
    if n == 2:
        return True
    for i in range(2,int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True
class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        ans = 0
        for i in range(left,right + 1):
            s = bin(i).count("1")
            if (isPrime(s)):
                ans += 1
        return ans
