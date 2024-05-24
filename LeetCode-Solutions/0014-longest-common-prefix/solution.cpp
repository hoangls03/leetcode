class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        int dem = 0;
        bool check = true;
        string ans;
        for ( int i = 0 ; i < str[0].size() && check ; ++i )
        {
            dem = 0;
            for ( int j = 0 ; j < str.size() && check ; ++j )
            {
                if ( str[j][i] == str[0][i] ) dem++;
            }
            if ( dem != str.size() )
            {
                break;
            }
            else ans += str[0][i];
        }
        return ans;
    }
};
