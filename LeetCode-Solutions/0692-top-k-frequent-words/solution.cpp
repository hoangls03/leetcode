class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<int,int> mark;
        map<string,int> mp;
        vector<string> clone;
        mp.clear();
        for  ( int i = 0 ; i < words.size() ; ++i ) {
            string s = words[i];
            if ( mp[s] == 0 ) clone.push_back(s);
            if ( mp[s] != 0 ) mark[i] = -1;
            mp[s]++;
        }
        vector<string> ans;
        sort(clone.begin(),clone.end(),[&](string a, string b) {
            if ( mp[a] == mp[b] ) return a > b;
            return mp[a] < mp[b];
        });
        for ( int i = clone.size() - 1 ; i >= 0 && k > 0 ; --i ) {
            ans.push_back(clone[i]);
            k--;
        }
        return ans;
    }
};
