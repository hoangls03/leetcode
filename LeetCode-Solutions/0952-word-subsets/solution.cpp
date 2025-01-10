class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> mark('z' + 1);
        for ( auto word : words2 ) {
            vector<int> count('z' + 1,0);
            for ( auto i : word ) {
                count[i]++;
            }
            for ( int i = 'a' ; i <= 'z' ; ++i ) {
                mark[i] = max(mark[i],count[i]);
            }
        }
        vector<string> ans;
        for ( auto word : words1 ) {
            vector<int> count('z' + 1,0);
            for ( auto i : word ) {
                count[i]++;
            }
            bool check = true;
            for ( int i = 'a' ; i <= 'z' ; ++i ) {
                if ( count[i] < mark[i] ) check = false;
            }
            if ( check ) ans.push_back(word);
        }
        return ans;
    }
};
