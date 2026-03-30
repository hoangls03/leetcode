class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> markEven('z' + 1), markOdd('z' + 1);
        int n = s1.size();
        for ( int i = 0 ; i < n ; ++i ) {
            if ( i & 1 ) {
                markOdd[s1[i]]++;
            } else {
                markEven[s1[i]]++;
            }
        }
        for ( int i = 0 ; i < n ; ++i ) {
            if ( i & 1 ) {
                markOdd[s2[i]]--;
            } else {
                markEven[s2[i]]--;
            }
        }
        for ( int i = 'a' ; i <= 'z' ; ++i ) {
            if ( markOdd[i] != 0 || markEven[i] != 0 ) {
                return false;
            }
        }
        return true;
    }
};
