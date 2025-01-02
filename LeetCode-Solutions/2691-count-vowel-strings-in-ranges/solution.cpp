class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> mark('z'+1);
        mark['a'] = 1;
        mark['e'] = 1;
        mark['i'] = 1;
        mark['o'] = 1;
        mark['u'] = 1;
        int n = words.size();
        vector<int> vowelSum(n,0);
        for ( int i = 0 ; i < n ; ++i ) {
            string s = words[i];
            char st = s[0];
            char end = s[s.size() - 1];
            if ( i > 0 ) vowelSum[i] = vowelSum[i-1];
            if ( mark[st] == 1 && mark[end] == 1 ) {
                vowelSum[i] = i == 0 ? 1 : vowelSum[i-1] + 1;
            } 
            
        }
        vector<int> ans;
        for ( auto q : queries ) {
            int l = 0;
            if ( q[0] > 0 ) l = vowelSum[q[0]-1];
            ans.push_back(vowelSum[q[1]] - l);
        }
        return ans;
    }
};
