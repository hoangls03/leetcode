const char vowel[] = {'a','e','i','o','u'};
class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        set<int> st;
        st.insert(n);
        for ( int i = 0 ; i < n ; ++i ) {
            bool check = true;
            for ( int j = 0 ; j < 5 ; ++j ) {
                if ( word[i] == vowel[j] ) {
                    check = false;
                }
            }
            if ( check ) {
                st.insert(i);
            }
        }
        int pos = 0;
        int con = 0;
        bool ok = false;
        long long ans = 0;
        vector<int> mark(26,0),vis(n,0);
        for ( int i = 0 ; i < n ; ++i ) {
            pos = max(pos,i);
            while ( pos < n && ( con < k || !ok ) ) {
                mark[word[pos]-'a'] += (vis[pos] == 0);
                
                ok = true;
                bool check = true;
                for ( int j = 0 ; j < 5 ; ++j ) {
                    if ( word[pos] == vowel[j] ) {
                        check = false;
                    }
                    if ( mark[vowel[j]-'a'] == 0 ) {
                        ok = false;
                        
                    }
                }
                if ( vis[pos] == 0 ) con += check;
                vis[pos] = 1;
                if ( !(con >= k && ok ) ) pos++;
            }
            if ( con == k && ok ) {
                auto it = st.upper_bound(pos);
                int fur = *it;
                ans += fur - pos;
            }
            mark[word[i]-'a']--;
            ok = true;
            bool check = true;
            for ( int j = 0 ; j < 5 ; ++j ) {
                if ( word[i] == vowel[j] ) {
                    check = false;
                }
                if ( mark[vowel[j]-'a'] == 0 ) {
                    ok = false;
                    
                }
            }
            con -= check;
        }
        return ans;
    }
};
