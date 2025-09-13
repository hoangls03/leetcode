class Solution {
public:
    int maxFreqSum(string s) {
        string vowel = "aeiou";
        vector<bool> check('z' + 1,false);
        for ( auto i : vowel ) {
            check[i] = true;
        }
        vector<int> mark('z' + 1);
        for ( auto i : s ) {
            mark[i]++;
        }
        int vowelfreq = 0;
        int consfreq = 0;
        for ( int i = 'a' ; i <= 'z' ; ++i ) {
            if ( check[i] ) vowelfreq = max(vowelfreq,mark[i]);
            else consfreq = max(consfreq,mark[i]);
        }
        return vowelfreq + consfreq;
    }
};
