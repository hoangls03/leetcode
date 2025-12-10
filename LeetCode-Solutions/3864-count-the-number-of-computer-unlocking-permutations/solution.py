class Solution:
    def countPermutations(self, complexity: List[int]) -> int:
        n = len(complexity)
        for i in range(1,n):
            if ( complexity[i] <= complexity[0] ):
                return 0
        
        ans = 1
        oo = 10**9 + 7
       
        for i in range(1,n):
            ans = ans*i%oo
        
        return ans


