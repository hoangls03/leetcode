class Solution {
public:
    int differenceOfSums(int n, int m) {
        int count = n/m;
        count = m*count*(count+1)/2;
        int sum = n*(n+1)/2;
        return sum - 2*count;
    }
};
