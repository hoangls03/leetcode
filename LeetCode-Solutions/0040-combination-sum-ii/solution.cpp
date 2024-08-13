auto init = []() { 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 
    return 0; 
}();
class Solution {
public:
    void findcombination(vector<int>& candidates, int target, vector<vector<int>>& ans, int pos, vector<int> temp ) {
        int n = candidates.size();
        if ( target == 0 ) ans.push_back(temp);
        if ( pos >= n || target < 0 ) return ;
        for ( int i = pos ; i < n ; ++i ) {
            if ( i == pos || candidates[i] != candidates[i-1] ) {
                temp.push_back(candidates[i]);
                findcombination(candidates,target-candidates[i],ans,i+1,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        findcombination(candidates,target,ans,0,{});
        return ans;
    }
};
