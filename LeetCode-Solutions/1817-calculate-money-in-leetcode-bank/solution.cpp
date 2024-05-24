class Solution {
public:
    int totalMoney(int n) {
        int ans = 0,temp = 0,add;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( i % 7 == 0 ) {
                temp++;
                add = temp;
            }
            else add++;
            ans += add;
        }
        return ans;
    }
};
