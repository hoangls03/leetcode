class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int n = s.size();
        int minChar = '0';
        int maxChar = '9';
        int markMin = -1;
        int markMax = -1;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( markMax == -1 && s[i] != maxChar ) markMax = s[i];
            if ( markMin == -1 && s[i] != minChar ) markMin = s[i];
        }
        string minS = s;
        string maxS = s;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( s[i] == markMax ) {
                maxS[i] = maxChar;
            }
            if ( s[i] == markMin ) {
                minS[i] = minChar;
            }
        }
        int maxNum = stoi(maxS);
        int minNum = stoi(minS);
        return maxNum - minNum;
    }
};
