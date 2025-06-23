class Solution {
public:
    bool checkPalind( string s ) {
        int n = s.size();
        for ( int i = 0 ; i < n ; ++i ) {
            if ( s[i] != s[n - 1 - i] ) {
                return false;
            }
        }
        return true;
    }
    string convertNum( long long n, int k ) {
        if ( n == 0 ) {
            return "0";
        }
        string ans = "";
        while ( n > 0 ) {
            ans += to_string(n%k);
            n /= k;
        }
        return ans;
    }
    long long kMirror(int k, int n) {
        long long sum = 0;
        long long len = 1;
        while ( n > 0 ) {
            long long half = (len + 1)/2;
            long long l = pow(10,half - 1);
            long long r = pow(10,half);
            for ( long long i = l ; i < r && n > 0 ; ++i ) {
                string s = to_string(i);
                string t = s;
                reverse(t.begin(),t.end());
                s = s + t.substr(len % 2);
                long long tmp = stoll(s);
                if ( checkPalind(convertNum(tmp,k)) ) {
                    sum += tmp;
                    n--;
                }
            }
            len++;
        }
        return sum;
    }
};
