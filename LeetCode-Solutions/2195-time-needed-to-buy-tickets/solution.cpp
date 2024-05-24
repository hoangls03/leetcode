class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int ans = 0;
        ans += k + 1;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( i <= k ) {
                tickets[i]--;
            }
        }
        for ( int i = 0 ; i < n ; ++i ) {
            ans += min(tickets[k],tickets[i]);
        }
        return ans;
    }
};
