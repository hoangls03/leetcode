class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        long long mark[26];
        for ( int i = 0 ; i < 26 ; ++i ) {
            mark[i] = 0;
        }
        for ( auto i : word2 ) {
            mark[i-'a']++;
        }
        long long count[26];
        for ( int i = 0 ; i < 26 ; ++i ) {
            count[i] = 0;
        }
        int n = word1.size();
        int pos = 0;
        bool match = true;
        vector<bool> visit(n,false);
        long long ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            match = true;
            pos = max(pos,i);
            for ( int j = 0 ; j < 26 ; ++j ) {
                if ( count[j] < mark[j] ) match = false;
            }
            while ( pos < n ) {
                if ( !visit[pos] ) {
                    count[word1[pos] - 'a']++;
                    visit[pos] = true;
                }
                match = true;
                for ( int j = 0 ; j < 26 ; ++j ) {
                    if ( count[j] < mark[j] ) match = false;
                }
                if ( match ) break;
                pos++;
            }
            if ( match ) ans += n - pos;
            count[word1[i]-'a']--;
        }   
        return ans;
    }
};
