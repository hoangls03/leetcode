class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string ans = "";
        for ( auto s : words ) {
            bool check = true;
            for ( int i = s.size()/2 ; i < s.size() ; ++i ) {
                if ( s[i] != s[s.size() - 1 - i ] ) {
                    check = false;
                }
            }
            if ( check ) {
                ans = s;
                break;
            }
           
        }
        return ans;
    }
};
