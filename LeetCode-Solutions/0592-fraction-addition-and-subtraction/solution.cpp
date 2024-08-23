class Solution {
public:
    void eval( int& numerator, int& denominator, long long x, long long y, int sign ) {
        long long temp = numerator*y + sign*x*denominator;
        long long temp1 = denominator*y;
        long long gcd = abs(__gcd(temp,temp1));
        temp /= gcd;
        temp1 /= gcd;
        numerator = temp;
        denominator = temp1;
    }
    string fractionAddition(string expression) {
        int numerator = 0;
        int denominator = 1;
        int n = expression.size();
        int pos = 0;
        int status = 1;
        if ( expression[0] == '-' ) {
            pos = 1;
            status = -1;
        } 
        if ( expression[0] == '+' ) {
            pos = 1;
            status = 1;
        }
        for ( int i = pos ; i < n ; ++i ) {
            if ( i == 0 || expression[i-1] == '-' || expression[i-1] == '+' ) {
                int a = expression[i] - '0';
                int b = expression[i+2] - '0';
                int add = 2;
                if ( expression[i+1] != '/' ) {
                    a = a*10 + (expression[i+1] - '0');
                    b = expression[i+3] - '0';
                    add = 3;
                } 
                i += add;
                if ( i+1 < n && expression[i+1] >= '0' && expression[i+1] <= '9' ) {
                    b = b * 10 + expression[i+1] - '0';
                    i++;
                }
                eval(numerator,denominator,a,b,status);
                
            }
            if ( expression[i] == '+' ) status = 1;
            if ( expression[i] == '-' ) status = -1;
        }
        
        string ans = "";
        if ( numerator < 0 ) ans += '-';
        numerator = abs(numerator);
        ans += to_string(numerator);
        ans += '/';
        ans += to_string(denominator);
        return ans;
    }
};
