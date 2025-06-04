class Solution {
public:
    string answerString(string word, int numFriends) {
        string ans = "";
        int n = word.size();
        if ( numFriends == 1 ) return word;
        int maxLength = n - numFriends + 1;
        for ( int i = 0 ; i < n ; ++i ) {
            int len = min(maxLength,n - i);
            ans = max(ans,word.substr(i,len));
        }
        return ans;
    }
};
