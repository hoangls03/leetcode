class Solution {
public:
    string makeFancyString(string s) {
        int cons = 1;
        string t = "";
        t += s[0];
        for ( int i = 1 ; i < s.size() ; ++i ) { 
            if ( s[i] == s[i-1] ) {
                cons++;
            } else {
                cons = 1;
            }
            if ( cons < 3 ) t += s[i];
        }
        return t;
    }
};
