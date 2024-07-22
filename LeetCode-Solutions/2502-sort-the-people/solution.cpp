class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = heights.size();
        map<int,string> mp;
        for ( int i = 0 ; i < n ; ++i ) {
            mp[heights[i]] = names[i];
        }
        sort(heights.begin(),heights.end(),greater<int>());
        vector<string> ans;
        for ( auto i : heights ) 
            ans.push_back(mp[i]);
        return ans;
    }
};
