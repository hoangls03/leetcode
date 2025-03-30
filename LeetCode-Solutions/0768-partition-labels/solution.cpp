class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> appear('z' + 1);
        int n = s.size();
        for ( int i = 0 ; i < n ; ++i ) {
            appear[s[i]] = i;
        }
        int r = 0;
        vector<int> ans;
        int pos = -1;
        for ( int i = 0 ; i < n ; ++i ) {
            r = max(r,i);
            r = max(appear[s[i]],r);
            if ( r == i ) {
                ans.push_back(i-pos);
                pos = i;
            }
        }
        return ans;
    }
};
