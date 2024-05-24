class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        num = " " + num;
        string ans = "";
        int count = 0,digit = -1;
        for ( int i = 1 ; i <= n ; ++i  ) {
            if ( num[i] == num[i-1] ) count++;
            else count = 0;
            if ( count == 2 ) {
                digit = max(digit,num[i]-'0');
            }
        }
        if ( digit == -1 ) return ans;
        for ( int i = 1 ; i <= 3 ; ++i ) {
            ans += digit+'0';
        }
        return ans;
    }
};
