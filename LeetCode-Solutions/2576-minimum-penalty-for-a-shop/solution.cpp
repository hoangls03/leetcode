class Solution {
public:
    int bestClosingTime(string customers) {
        int countY = 0;
        for ( auto i : customers ) {
            countY += (i == 'Y');
        }
        int countN = 0;
        int n = customers.size();
        int ans = 0;
        int penalty = n + 1;
        for ( int i = 0 ; i <= n ; ++i ) {            
            int res = countY + countN;
            if ( res < penalty ) {
                ans = i;
                penalty = res;
            }
            if ( i < n ) {
                countY -= (customers[i] == 'Y');
                countN += (customers[i] == 'N');
            }
        }
        return ans;
    }
};
