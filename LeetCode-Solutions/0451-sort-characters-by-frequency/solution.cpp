#define ci pair<int,char>
#define fi first
#define se second 
class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        vector<ci> ans('z' + 1);
        vector<int> count('z' + 1,0);
        for ( int i = 0 ; i < n ; ++i ) {
            count[s[i]]++;
        }
        for ( int i = '0' ; i <= 'z' ; ++i ) {
            ans[i].fi = count[i];
            ans[i].se = i;
        }
        sort(ans.begin(),ans.end());
        string answer = "";
        for ( int i = 'z' ; i >= '0' ; --i ) {
            if ( count[ans[i].se] != 0 ) {
                for ( int j = 1 ; j <= count[ans[i].se] ; ++j ) {
                    answer += ans[i].se;
                }
            }
        }
        return answer;
    }
};
