class Solution {
public:
    void BFS(string source, map<string,int>& check, map<string,int>& block , string target) {
        queue<string> q;
        q.push(source);
        while ( q.size() ) {
            source = q.front();
            string s = source;
            q.pop();
            if ( block[s] == 1 ) continue;
            for ( int i = 0 ; i < source.size() ; ++i ) {
                char temp,prev_temp;
                prev_temp = s[i];
                if ( source[i] == '9' ) {
                    temp = '0';
                } else temp = source[i] + 1;
                source[i] = temp;
                if ( check[source] == 0 ) {
                    q.push(source);
                    check[source] = check[s] + 1;
                    if ( source == target ) break;
                }

                source[i] = prev_temp;

                if ( source[i] == '0' ) {
                    temp = '9';
                } else temp = source[i] - 1;
                source[i] = temp;
                if ( check[source] == 0 ) {
                    
                    q.push(source);
                    check[source] = check[s] + 1;
                    if ( source == target ) break;
                }

                source[i] = prev_temp;
            }
        }
    }
    int openLock(vector<string>& deadends, string target) {
        int ans = 0;
        if ( target == "0000" ) return 0;
        map<string,int> block;
        map<string,int> check;
        block.clear();
        check.clear();
        for ( auto i : deadends ) {
            block[i] = 1;
        }
        string source = "0000";
        BFS(source,check,block,target);
        if ( check[target] == 0 ) ans = -1;
        else ans = check[target];
        return ans;
    }
};
