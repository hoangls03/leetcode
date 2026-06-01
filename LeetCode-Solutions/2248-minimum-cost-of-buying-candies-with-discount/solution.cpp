class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int sum = 0;
        int n = cost.size();
        if ( n < 3 ) {
            for ( auto i : cost ) {
                sum += i;
            }
            return sum;
        }
        for ( int i = n - 1 ; i >= 0 ; i -= 3 ) {
            if ( i > 0 ) {
                sum += cost[i] + cost[i-1];
            } else {
                sum += cost[i];
            }
        }
        return sum;
    }
};
