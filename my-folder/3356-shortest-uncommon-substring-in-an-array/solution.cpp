class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        map<string,int> mp[105],count;
        for ( int i = 0 ; i <= 100 ; ++i ) {
            mp[i].clear();
        }
        count.clear();
        vector<string> ans;
        for ( int k = 0 ; k < arr.size() ; ++k ) {
            string s = arr[k];
            int n = s.size();
            string t = "";
            for ( int i = 0 ; i < n ; ++i ) {
                string temp = "";
                for ( int j = i; j < n ; ++j ) {
                    temp += s[j];
                    count[temp]++;
                    mp[k][temp]++;
                }
            }
        }
        for ( int k = 0 ; k < arr.size() ; ++k ) {
            string s = arr[k];
            int n = s.size();
            string t = "";
            for ( int i = 0 ; i < n ; ++i ) {
                string temp = "";
                for ( int j = i; j < n ; ++j ) {
                    temp += s[j];
                    if ( mp[k][temp] == count[temp] ) {
                        if ( t == "" || t.size() > temp.size() || (t.size() == temp.size() && t > temp) ) t = temp;
                    }
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};
