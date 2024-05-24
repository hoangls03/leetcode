class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size();
        int n = bank[0].size();
        int temp = 0,ans = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            int count = 0;
            for ( auto j : bank[i] ) {
                if ( j == '1' ) count++;
            }
            if ( count > 0 ) {
                ans += temp*count;
                temp = count;
            }
        }
        return ans;
    }
};
