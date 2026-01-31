class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        sort(letters.begin(),letters.end());
        for ( auto i : letters ) {
            if ( i > target ) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
