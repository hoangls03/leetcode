class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for ( auto i : queries ) {
            bool ok = false;
            for ( auto j : dictionary ) {
                if ( i.size() == j.size() ) {
                    int n = i.size();
                    int count = 0;
                    for ( int k = 0 ; k < n ; ++k ) {
                        count += (i[k] != j[k]);
                    }
                    if ( count <= 2 ) {
                        ok = true;
                        break;
                    }
                }
            }
            if ( ok ) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
