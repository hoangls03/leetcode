class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> score_temp;
        int n = score.size();
        score_temp = score;
        vector<int> mark(1e6+5,0);
        sort(score_temp.begin(),score_temp.end());
        for ( int i = 0 ; i < score_temp.size() ; ++i ) {
            mark[score_temp[i]] = n - i;
        }
        vector<string> ans;
        for ( auto i : score ) {
            if ( mark[i] == 1 ) {
                ans.push_back("Gold Medal");
            }
            if ( mark[i] == 2 ) {
                ans.push_back("Silver Medal");
            }
            if ( mark[i] == 3 ) {
                ans.push_back("Bronze Medal");
            }
            if ( mark[i] > 3 ) {
                string temp = to_string(mark[i]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
