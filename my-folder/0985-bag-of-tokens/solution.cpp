class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n = tokens.size() - 1;
        int score = 0;
        if ( tokens.size() == 0 || power < tokens[0] ) return 0;
        score++;
        power -= tokens[0];
        int l = 1;
        int r = n;
        while ( l <= r ) {
            if ( power < tokens[l] ) {
                if ( l == r ) break;
                if ( l < r && score > 0 ) {
                    power += tokens[r];
                    score--;
                    r--;
                }
            }
            if ( power >= tokens[l] ) {
                power -= tokens[l];
                score++;
            }
            l++;
        }
        return score;
    }
};
