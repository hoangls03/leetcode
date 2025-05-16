class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size(),res = 0,pos;
        vector<string> ans;
        vector<int> dp(n,1),mark(n,-1);
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 0 ; j < i ; ++j ) {
                if ( groups[j] != groups[i] && words[j].size() == words[i].size() && dp[j] + 1 > dp[i] ) {
                    int count = 0;
                    for ( int z = 0 ; z < words[i].size() ; ++z ) {
                        if ( words[i][z] != words[j][z] ) {
                            count++;
                        }
                    }
                    if ( count == 1 ) { 
                        mark[i] = j;
                        dp[i] = dp[j] + 1;
                    }
                }
            }
            if ( dp[i] > res ) {
                res = dp[i];
                pos = i;
            }
        }
        while ( pos != -1 ) {
            ans.push_back(words[pos]);
            pos = mark[pos];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
