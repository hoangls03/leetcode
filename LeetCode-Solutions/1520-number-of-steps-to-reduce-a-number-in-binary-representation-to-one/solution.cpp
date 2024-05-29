class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        s = '0' + s;
        bool check = true;
        int ans = 0;
        while ( check ) {
            check = false;
            for ( int i = n - 1; i >= 0 ; --i ) {
                if ( s[i] == '1' ) check = true; 
            }
            if ( !check ) break;
            ans++;
            if ( s[n] == '0' ) {
                for ( int i = n ; i >= 1 ; --i ) {
                    s[i] = s[i-1];
                }
                s[0] = '0';
            } else {
                bool carry = true;
                s[n] = '0';
                for ( int i = n - 1 ; i >= 0 ; --i ) {
                    if ( carry ) {
                        if ( s[i] == '1' ) {
                            s[i] = '0';
                        } else {
                            s[i] = '1';
                            carry = false;
                        }
                    }
                }
            }   

        }
        return ans;
    }
};
