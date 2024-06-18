#define ii pair<int,int>
#define fi first
#define se second
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<ii> arr;
        int n = difficulty.size();
        for ( int i = 0 ; i < n ; ++i ) {
            arr.push_back({difficulty[i],profit[i]});
        }
        sort(arr.begin(),arr.end());
        int ans = 0;
        int m = worker.size();
        int max_profit = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            max_profit = max(max_profit,arr[i].se);
            profit[i] = max_profit;
        }
        for ( auto ability : worker ) {
            int l = 0;
            int r = n - 1;
            int temp = 0;
            while ( l <= r ) {
                int mid = ( l + r ) >> 1;
                if ( arr[mid].fi <= ability ) {
                    temp = profit[mid];
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            ans += temp;
        }
        return ans;
    }
};
