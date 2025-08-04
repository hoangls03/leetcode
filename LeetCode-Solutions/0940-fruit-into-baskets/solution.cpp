class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int pos = 0;
        vector<int> mark(n);
        int ans = 0;
        int count = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            while ( pos < n ) {
                if ( mark[fruits[pos]] == 0 && count + 1 > 2 ) {
                    break;
                }
                if ( mark[fruits[pos]] == 0 ) {
                    count++;
                }
                mark[fruits[pos]]++;
                pos++;
            }
            ans = max(pos - i,ans);
            if ( mark[fruits[i]] == 1 ) {
                count--;
            }
            mark[fruits[i]]--;
        }
        return ans;
    }
};
