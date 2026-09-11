class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int ans = 0;
        int n = digits.size();
        vector<int> mark(1000,0);
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                for ( int z = 0 ; z < n ; ++z ) {
                    if ( i != j && j != z && z != i ) {
                        if ( digits[i] != 0 ) {
                            int val = digits[i]*100 + digits[j]*10 + digits[z];
                            ans += (mark[val] == 0 && val % 2 == 0);
                            mark[val]++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
