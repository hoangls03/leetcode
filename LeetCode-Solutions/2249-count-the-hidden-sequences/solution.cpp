class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long minNum = 0, maxNum = 0, num = 0;
        for ( auto i : differences ) {
            num += i;
            minNum = min(minNum,num);
            maxNum = max(maxNum,num);
        }
        long long diff = minNum - lower;
        maxNum -= diff;
        int ans = 0;
        if ( maxNum <= upper ) {
            ans = upper - maxNum + 1;
        }
        return ans;
    }
};
