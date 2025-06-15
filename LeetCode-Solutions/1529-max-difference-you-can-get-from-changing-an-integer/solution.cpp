class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int n = s.size();
        string maxNum = s;
        string minNum = s;
        int maxChar = -1;
        int minChar = -1;
        int count = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( s[i] != '9' && maxChar == -1 ) {
                maxChar = s[i];
            }
            if ( s[i] != '0' && minChar == -1 ) {
                minChar = s[i];
            }
            if ( s[i] == maxChar ) {
                maxNum[i] = '9';
            }
            if ( s[i] == minChar ) {
                count++;
            }
            count += ( s[i] == '0' );
        }
        minChar = -1;
        if ( count == n || s[0] != '1' ) {
            for ( int i = 0 ; i < n ; ++i ) {
                if ( minChar == -1 && s[i] > '1' ) {
                    minChar = s[i];
                }
                if ( s[i] == minChar ) {
                    minNum[i] = '1';
                }
            }
        } else {
            int save = '0';
            if ( s[0] == '1' ) {
                save = '1';
            }
            for ( int i = 0 ; i < n ; ++i ) {
                if ( minChar == -1 && s[i] > save ) {
                    minChar = s[i];
                }
                if ( s[i] == minChar ) {
                    minNum[i] = '0';
                }
            }
        }
        int minN = stoi(minNum);
        int maxN = stoi(maxNum);
        return maxN - minN;
    }
};
