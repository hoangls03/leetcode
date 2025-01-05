class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> offset(n + 1);
        for ( auto shift : shifts ) {
            int move = 1;
            if ( shift[2] == 0 ) move = -1;
            offset[shift[0]] += move;
            offset[shift[1] + 1] -= move;
        }
        vector<int> sum(n);
        for ( int i = 0 ; i < n ; ++i ) {
            sum[i] = i == 0 ? offset[i] : sum[i-1] + offset[i];
            s[i] = ((s[i] - 'a' + sum[i])%26 + 26)%26 + 'a';
        }
        return s;
    }
};
