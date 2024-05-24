class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        vector<int> count(26,0);
        vector<int> init(26,0);
        for ( auto ch : letters ) {
            init[ch-'a']++;
        }
        for ( int i = 0 ; i < 26 ; ++i ) {
            cout<<init[i]<<" ";
        }
        cout<<'\n';
        int ans = 0;
        for ( int mask = 0 ; mask < ( 1  << n ) ; ++mask ) {
            for ( int i = 0 ; i < 26 ; ++i ) {
                count[i] = 0;
            }
            for ( int j = 0 ; j < n ; ++j ) {
                if ( mask & (1 << j) ) {
                    for ( auto ch : words[j] ) {
                        count[ch-'a']++;
                    }
                }
            }
            bool check = true;
            for ( int i = 0 ; i < 26 && check ; ++i ) {
                if ( count[i] > init[i] ) check = false;
            }
            if ( check ) {
                int tmp = 0;
                for ( int i = 0 ; i < 26 ; ++i ) {
                    tmp += count[i]*score[i];
                }
                ans = max(ans,tmp);
            }
        }
        return ans;
    }
};
