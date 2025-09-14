class Solution {
public:
    string lowerString( string s ) {
        string ans = "";
        for ( auto i : s ) {
            ans += tolower(i);
        }
        return ans;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        map<string,string> mark;
        map<string,string> mark1;
        map<string,string> mark2;
        string vowel = "aeiou";
        vector<bool> markVowel('z' + 1);
        for ( auto i : vowel ) {
            markVowel[i] = true;
        }
        for ( auto i : wordlist ) {
            if ( mark[i] == "") mark[i] = i;
        }
        for ( auto i : wordlist ) {
            string s = lowerString(i);
            if ( mark1[s] == "") mark1[s] = i;
        }
        for ( auto i : wordlist ) {
            string s = lowerString(i);
            for ( auto& j : s ) {
                if ( markVowel[j] ) j = 'a';
            }
            if ( mark2[s] == "") mark2[s] = i;
        }
        vector<string> ans;
        for ( auto i : queries ) {
            if ( mark[i] != "") {
                ans.push_back(i);
                continue;
            }
            string s = lowerString(i);
            if ( mark1[s] != "" ) {
                ans.push_back(mark1[s]);
                continue;
            } 
            for ( auto& j : s ) {
                if ( markVowel[j] ) j = 'a';
            }
            if ( mark2[s] != "" ) {
                ans.push_back(mark2[s]);
                continue ;
            }
            ans.push_back("");

        }
        return ans;
    }
};
