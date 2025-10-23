class Solution {
public:
    bool hasSameDigits(string s) {
        vector<int> digit;
        for ( auto i : s ) {
            digit.push_back(i - '0');
        }
        while ( digit.size() > 2 ) {
            vector<int> newDigit;
            for ( int i = 0 ; i < digit.size() - 1; ++i ) {
                newDigit.push_back((digit[i] + digit[i+1])%10);
            }
            digit = newDigit;
        }
        return (digit[0] == digit[1]);
    }
};
