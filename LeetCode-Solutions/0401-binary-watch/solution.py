class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        ans = []
        for hour in range(12):
            for minute in range(60):
                count = hour.bit_count() + minute.bit_count()
                if count == turnedOn:
                    ans.append(str(hour) + ":" + str(minute).zfill(2))
        return ans
