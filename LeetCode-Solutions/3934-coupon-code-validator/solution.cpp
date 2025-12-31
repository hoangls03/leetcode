class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        map<string,int> mp;
        mp["electronics"] = 1;
        mp["grocery"] = 2;
        mp["pharmacy"] = 3;
        mp["restaurant"] = 4;
        map<char,bool> markCh;
        for ( char i = 'a' ; i <= 'z' ; ++i ) {
            markCh[i] = true;
        }
        for ( char i = 'A' ; i <= 'Z' ; ++i ) {
            markCh[i] = true;
        }
        for ( char i = '0' ; i <= '9' ; ++i ) {
            markCh[i] = true;
        }
        markCh['_'] = true;
        int n = code.size();
        vector<string> ans;
        vector<pair<int,string>> save;
        for ( int i = 0 ; i < n ; ++i ) {
            bool check = false;
            for ( auto j : code[i] ) {
                if ( !markCh[j] ) {
                    check = false;
                    break;
                } else {
                    check = markCh[j];
                }
            }
            if ( check && mp[businessLine[i]] != 0 && isActive[i] ) {
                save.push_back({mp[businessLine[i]],code[i]});
            }
        }
        sort(save.begin(),save.end());
        for ( auto i : save ) {
            ans.push_back(i.second);
        }
        return ans;
    }
};
