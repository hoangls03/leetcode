class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> mark(n,0);
        int ans = 0;
        for ( auto i : fruits ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( mark[j] == 0 && baskets[j] >= i ) {
                    mark[j] = 1;
                    ans++;
                    break;
                }
            }
        }
        return n - ans;
    }
};
