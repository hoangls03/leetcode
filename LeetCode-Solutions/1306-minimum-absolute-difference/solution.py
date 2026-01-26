class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        n = len(arr)
        minVal = 10**9
        ans = []
        for i in range(n - 1):
            minVal = min(minVal,arr[i+1] - arr[i])
        for i in range(n - 1):
            if (arr[i + 1] - arr[i] == minVal):
                ans.append([arr[i],arr[i+1]])
        return ans
