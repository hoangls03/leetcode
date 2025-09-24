class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool sign = false;
        if ( (numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0) ) {
            sign = true;
        }
        string ans = "";
        if ( sign ) ans += '-';
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);
        long long q = num/den;
        long long r = num%den;
        ans += to_string(q);
        
        if ( r == 0 ) return ans;
        map<long long,int> mp;
        string frac = "";
        ans += '.';
        for ( int i = 0 ; r != 0 ; ++i ) {
            if ( mp[r] ) {
                frac.insert(mp[r],"(");
                frac += ')';
                break;
            }
            mp[r] = i;
            r *= 10;
            frac += ('0' + r/den);
            r %= den;
        }
        ans += frac;
        return ans;
    }
};
