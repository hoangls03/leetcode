class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> digits;
        while ( n > 0 ) {
            digits.push_back(n % 10);
            n /= 10;
        }
        sort(digits.begin(),digits.end());
        do {
            int num = 0;
            bool check = false;
            for ( auto i : digits ) {
                if ( i != 0 ) {
                    check = true;
                } else {
                    if ( !check ) {
                        break;
                    }
                }
                num = num*10 + i;
            }
            if ( !check ) {
                continue ;
            }
            if ( (num & (num - 1)) == 0 ) return true;
        }
        while ( next_permutation(digits.begin(),digits.end()));
        return false;
    }
};
