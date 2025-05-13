const int oo = 1e9 + 7;
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> count('z' + 1);
        for ( auto ch : s ) {
            count[ch]++;
        }
        for ( int i = 0 ; i < t ; ++i ) {
            vector<int> tmp('z' + 1);
            tmp['a'] = count['z'];
            tmp['b'] = (count['a'] + count['z'])%oo;
            for ( int j = 'c' ; j <= 'z' ; ++j ) {
                tmp[j] = count[j-1];
            }
            count = move(tmp);
        }
        int ans = 0;
        for ( int i = 'a' ; i <= 'z' ; ++i ) {
            ans = (ans + 1LL*count[i])%oo;
        }
        return ans;
    }
};
