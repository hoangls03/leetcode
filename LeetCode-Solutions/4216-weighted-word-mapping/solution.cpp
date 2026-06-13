class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for ( auto s : words ) {
            int sum = 0;
            for ( auto i : s ) {
                sum += weights[i - 'a'];
                sum %= 26;
            }
            ans += (char) (25 - sum + 'a');
        }
        return ans;
    }
};
