class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        map<string,int> mp;
        for ( auto word : words ) {
            int n = word.size();
            for ( int i = 0 ; i < n ; ++i ) {
                for ( int j = 1 ; j <= min(n- i,n-1) ; ++j ) {
                    string tmp = word.substr(i,j);
                    mp[tmp]++;
                }
            }
        }
        vector<string> ans;
        for ( auto word : words ) {
            if ( mp[word] ) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};
