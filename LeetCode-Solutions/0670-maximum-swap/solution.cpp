class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits;
        while ( num > 0 ) {
            digits.push_back(num%10);
            num /= 10;
        }
        reverse(digits.begin(),digits.end());
        int n = digits.size();
        int pos = -1;
        int digit;
        vector<int> maxNum(n);
        maxNum[n-1] = n-1;
        for ( int i = n - 2 ; i >= 0 ; --i ) {
            maxNum[i] = maxNum[i+1];
            if ( digits[i] > digits[maxNum[i+1]] ) {
                maxNum[i] = i;
            }
        }
        for ( int i = 0 ; i < n ; ++i ) {
            if ( maxNum[i] != i && digits[i] != digits[maxNum[i]] ) {
                swap(digits[i],digits[maxNum[i]]);
                break;
            }
        }
        for ( auto i : digits ) {
            num = num*10 + i;
        }
        return num;
    }
};
