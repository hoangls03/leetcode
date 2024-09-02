class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        int n = chalk.size();
        for ( auto i : chalk ) {
            sum += i;
        }
        k %= sum;
        sum = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            sum += chalk[i];
            if ( k < sum ) {
                return i;
            }
        }
        return 0;
    }
};
