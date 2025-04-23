class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> count(10000,0);
        int maxSize = 0;
        for ( int i = 1 ; i <= n ; ++i ) {
            int tmp = i;
            int digitSum = 0;
            while ( tmp > 0 ) {
                digitSum += tmp%10;
                tmp /= 10;
            }   
            count[digitSum]++;
            maxSize = max(maxSize,count[digitSum]);
        }
        int ans = 0;
        for ( int i = 0 ; i <= 36 ; ++i ) {
            ans += count[i] == maxSize;
        }
        return ans;
    }
};
