const string digit[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
const string teen[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const string ten[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
const string thousand[] = {"Thousand","Million","Billion"};
class Solution {
public:
    string numberToWords(int num) {
        if ( num == 0 ) return digit[0];
        string ans = processhundred(num);
        num /= 1000;
        for ( int i = 0 ; i < 3 ; ++i ) {
            int temp = num%1000;
            num /= 1000;
            if ( temp > 0 ) ans = processhundred(temp) + " " + thousand[i] + " " + ans;
        }
        if ( ans[ans.size() - 1 ] == ' ' ) ans.erase(ans.size()-1,1);
        return ans;
    }
    string processhundred(int num) {
        string ans = "";
        int pos = 0;
        int digit_ch = num%10;
        num /= 10;
        int ty_ch = num%10;
        num /= 10;
        int hundred = num%10;
        if ( hundred > 0 ) {
            ans += digit[hundred] + " Hundred ";
        }
        if ( ty_ch == 1 ) {
            ans += teen[digit_ch];
        }
        if ( ty_ch > 1 ) {
            ans += ten[ty_ch] + " ";
        }
        if ( ty_ch != 1 && digit_ch > 0 ) {
            ans += digit[digit_ch];
        }
        if ( ans.size() > 0 && ans[ans.size() - 1 ] == ' ' ) ans.erase(ans.size()-1,1);
        return ans;

    }
};
