class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0,count = 0;
        bool check = true;
        for ( auto i : s ) {
            if ( i != ' ' ) {
                if ( !check ) count = 0;
                count++;
                check = true;
            } else {
                check = false;
            }
        }
        return count;
    }
};
