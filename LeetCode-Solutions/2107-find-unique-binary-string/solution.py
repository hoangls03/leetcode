class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        n = len(nums)
        for i in range(0, 2**n):
            check = True
            for j in nums:
                if ( int(j,2) == i ):
                    check = False
            if check == True:
                return bin(i)[2:].zfill(n)
        return '0'
