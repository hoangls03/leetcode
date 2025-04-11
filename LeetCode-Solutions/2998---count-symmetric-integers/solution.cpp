class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for ( int i = low ; i <= high ; ++i ) {
            string s = to_string(i);
            int n = s.size();
            int sum = 0;
            int temp = 0;
            if (n & 1 ) continue;
            for ( int j = 0 ; j < n ; ++j ) {
                sum += s[j] - '0';
                if ( j == n/2 - 1 ) {
                    temp = sum;
                }
            }
            if ( temp* 2 == sum ) {
                ans++;
            }
        }
        return ans;
    }
};
