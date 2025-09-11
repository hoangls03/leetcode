class Solution {
public:
    string sortVowels(string s) {
        string vowels = "aeiouAEIOU";
        int n = s.size();
        vector<char> save;
        for ( auto i : s ) {
            for ( int j = 0 ; j < vowels.size() ; ++j ) {
                if ( vowels[j] == i ) {
                    save.push_back(i);
                    break;
                }
            }
        }
        sort(save.rbegin(),save.rend());
        string ans = "";
        for ( auto i : s ) {
            bool ok = true;
            for ( int j = 0 ; j < vowels.size() && ok; ++j ) {
                if ( vowels[j] == i ) {
                    ok = false;
                    break;
                }
            }
            if ( ok ) ans += i;
            else {
                ans += save[save.size() - 1];
                save.pop_back();
            }
        }
        return ans;
    }
};
