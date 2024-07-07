class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int blank = 0;
        while ( numBottles + blank >= numExchange ) {
            int temp = (numBottles+blank)/numExchange;
            ans += temp; 
            blank = numBottles + blank - temp*numExchange;
            numBottles = temp;
        }
        return ans;
    }
};
