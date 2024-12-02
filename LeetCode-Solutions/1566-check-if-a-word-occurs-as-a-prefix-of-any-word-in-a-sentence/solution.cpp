class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = searchWord.size();
        int m = sentence.size();
        int index = 0;
        int word = -1;
        for ( int i = 0 ; i <= m - n ; ++i ) {
            string temp = sentence.substr(i,n);
            if ( sentence[i] == ' ' ) {
                word = -1;
            } else {
                if ( word == -1 ) {
                    index++;
                    if ( temp == searchWord ) {
                        return index;
                    }
                } 
                word = i;
            }
        }
        return -1;
    }
};
