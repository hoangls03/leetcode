class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        vector<string> ans1;
        int n = words.size();
        int check = 0, check1 = 1;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( groups[i] == check ) {
                ans.push_back(words[i]);
                check = 1 - check;
            }
        }
        for ( int i = 0 ; i < n ; ++i ) {
            if ( groups[i] == check1 ) {
                ans1.push_back(words[i]);
                check1= 1 - check1;
            }
        }
        if ( ans.size() > ans1.size() ) return ans;
        return ans1;
    }
};
