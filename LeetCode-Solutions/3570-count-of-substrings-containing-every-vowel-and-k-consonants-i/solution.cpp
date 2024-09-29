const char vowel[] = {'a','e','i','o','u'};
class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int n = word.size();
        vector<int> mark(26,0);
        int ans = 0;
        int consonants = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 0 ; j < 26 ; ++j ) {
                mark[j] = 0;
            }
            consonants = 0;
            for ( int j = i ; j < n ; ++j ) {
                mark[word[j]-'a']++;
                bool check = true;
                for ( int z = 0 ; z < 5 ; ++z ) {
                    char ch = word[j];
                    if ( ch == vowel[z] ) {
                        check = false;
                    }
                }
                consonants += check;
                check = true;
                for ( int z = 0 ; z < 5 ; ++z ) {
                    if ( mark[vowel[z]-'a'] == 0 ) check = false;
                }
                if ( i == 6 && j == 11 ) {
                }
                if ( consonants == k && check ) {
                    ans++;
                }

            }
        }
        return ans;
    }
};
