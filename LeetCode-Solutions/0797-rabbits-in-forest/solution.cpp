class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> count(1001,0);
        for ( auto i : answers ) {
            i++;
            count[i]++;
        }
        int ans = 0;
        for ( int i = 0 ; i <= 1000 ; ++i ) {
            if ( count[i] != 0 ) {
                int tmp = count[i]/i;
                ans += i*tmp;
                if ( count[i] % i != 0 ) ans += i;
            }
        }
        return ans;
    }
};
