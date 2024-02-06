class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,int> mp;
        int count = 1;
        
        for ( auto i : strs ) {
            string temp = i;
            sort(temp.begin(),temp.end());
            if ( mp[temp] == 0 ) mp[temp] = count++;
        }
        vector<vector<string>> ans(count-1);
        for ( auto i : strs ) {
            string temp = i;
            sort(temp.begin(),temp.end());
            ans[mp[temp]-1].push_back(i);
        }
        return ans;
    }
};
