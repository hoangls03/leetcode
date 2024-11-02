class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        if ( sentence[0] != sentence[n-1] ) return false;
        char prev = ' ';
        for ( int i = 0 ; i < n ; ++i ) {
            if ( i > 0 && sentence[i-1] == ' ' ) {
                if ( sentence[i] != prev ) return false; 
            }
            if ( sentence[i] != ' ' ) {
                prev = sentence[i];
            }
        }
        return true;
    }
};
