class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        capacity.sort(reverse = True)
        sumApple = sum(apple)
        sumCap = 0
        for i in range(len(capacity)):
            sumCap += capacity[i]
            if sumCap >= sumApple:
                return i + 1
        return len(capacity)

