class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        n--;
        while ( n ) {
            string t = s;
            for ( auto& i : t ) {
                i = '1' - i + '0';
            }
            reverse(t.begin(),t.end());
            s += "1" + t;
            n--;
        }
        return s[k-1];
    }
};
