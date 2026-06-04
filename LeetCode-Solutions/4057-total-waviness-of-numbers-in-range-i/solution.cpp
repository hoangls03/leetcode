class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for ( int i = num1 ; i <= num2 ; ++i ) {
            vector<int> digits;
            int tmp = i;
            while ( tmp > 0 ) {
                digits.push_back(tmp%10);
                tmp /= 10;
            }
            int n = digits.size();
            for ( int j = 1 ; j < n ; ++j ) {
                if ( j + 1 < n ) {
                    if ( digits[j] > max(digits[j-1],digits[j+1]) || digits[j] < min(digits[j-1],digits[j+1])) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
