class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> count1(26,0),count2(26,0),count3(1e5,0);
        for ( auto i : word1 ) {
            count1[i-'a']++;
        }
        for ( auto i : word2 ) {
            count2[i-'a']++;
        }
        for ( int i = 0 ; i < 26 ; ++i ) {
            if ( (count1[i] == 0 && count2[i] != 0) || (count1[i] != 0 && count2[i] == 0) ) {
                return false;
            }
            count3[count2[i]]++;
        }
        for ( int i = 0 ; i < 26 ; ++i ) {
            if ( count1[i] != 0 ) {
                if ( count3[count1[i]] == 0 ) {
                    return false;
                }
                count3[count1[i]]--;
            }
        }
        return true;
    }
};
